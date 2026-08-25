*** UID:0000EK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Layer;
class TextBoxPane;

class TextButtonExControlPane : public ButtonControlPane
{
public:
    TextButtonExControlPane(const wchar_t *text, const RectBounds &bounds);
    virtual ~TextButtonExControlPane();

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();

    virtual void Enable();
    virtual void Disable();
    virtual short GetText(wchar_t *destination, short maxCharacters);

protected:
    virtual void SetVisualState(unsigned char visualState);
    virtual void OnPaint();

private:
    void CalculateLabelRect(RectBounds *outRect);
    void CalculateLabelRect(RectBounds *outRect, const wchar_t *text);

    TextBoxPane *m_labelTextBox;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextButtonExControlPane

## Status

- Confidence: very strong for inheritance, exact `0x110` layout, method/vtable contract, text-provider ownership, ordinary destructor source, label-rectangle helpers, layer/enable behavior, paint resources, and compiler-support separation; strong for inferred original private/helper spellings and current source-file route.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md), adjacent to [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- Core memory: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Evidence basis: live IDA MCP function listing, xrefs, vtable slots, disassembly, and decompilation on 2026-06-04.

## Class Purpose

`TextButtonExControlPane` is an extended text-labeled button. It owns a `TextBoxPane` label child, centers label bounds when visual state changes, enables/disables the label with the control, adds/removes the child through layer operations, and paints BUTTONEX-style graphics with optional text/icon overlays.

## Field And Helper Names

The child pointer at `this+0x10c` is best documented as `TextBoxPane *m_labelTextBox`. Constructor evidence stores a `TextBoxPane` built by [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md) at that offset; text access and both raw label-rectangle helpers consume the same child; and the ordinary destructor deletes it. The exact object is `0x110` bytes: inherited `ButtonControlPane` occupies `0x10c`, and this pointer is the sole derived field. `m_textBoxPane` was a reasonable historical fallback before the role was closed, but `m_labelTextBox` now supplies one consistent human source name rather than retaining an offset or IDA label.

The retained raw helper pair at [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) is best named as `CalculateLabelRect` overloads: the provider/current-text overload at `0x00495aa0-0x00495b51` copies from `m_labelTextBox`, and the supplied-text overload at `0x00495b60-0x00495be3` measures a caller-provided `const wchar_t *`. B007's raw PE scan found no direct branch/call or VA/RVA pointer route to either raw start, so these remain retained unreferenced private helpers rather than vtable callbacks or proven live direct-call methods. That reachability caveat caps final confidence but no longer blocks first-draft C++ on the child page.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TextButtonExControlPane` | `0x00495450-0x004955dc` | Constructs the generic `ButtonControlPane` base, installs `TextButtonExControlPane` vtables, centers the initial label rect, allocates a 372-byte text-provider child, attaches it, and shows it. |
| `~TextButtonExControlPane` | [UID:0003NA][0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown](by-memory/0x004955e0-0x00495615.TextButtonExControlPaneRawTeardown.md) | Exact modeled IDA function `TextButtonExControlPane__Destructor` with zero xrefs; human body is exactly `delete m_labelTextBox;`, while vptr stores, virtual delete lowering, and Pane teardown are compiler output. |
| `SetVisualState` | `0x00495620-0x0049574c` | Re-reads provider text, recomputes centered label bounds, applies the disabled-state offset for state `11`, updates the child rect, stores the visual-state byte, and invalidates. |
| `GetText` | `0x00495750-0x004957b2` | Copies provider text into the caller buffer up to the requested count, writes a UTF-16 null terminator, and returns the copied count. |
| `Enable` | `0x004957c0-0x00495836` | Enables the inherited control and label child, applies child state value `134`, invalidates provider and owner bounds, and sets inherited `m_enabled`. |
| `Disable` | `0x00495840-0x004958b6` | Disables the label child with state value `128`, invalidates provider and owner bounds, and clears inherited `m_enabled`. |
| `AddToLayer` | `0x004958c0-0x0049591f` | Chains the inherited layer-add slot, queries child bounds through vtable slot `+0x28`, then adds the label child through its layer slot `+0x30`. |
| `RemoveFromLayer` | `0x00495920-0x00495936` | Removes the label child through slot `+0x38`, then chains the inherited layer-removal slot. |
| `OnPaint` | `0x00495940-0x00495a95` | Draws BUTTONEX resources, applies disabled-state offset for state `11`, and optionally overlays text/icon variants based on local flags. |
| `CalculateLabelRect` overloads | [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) | Two IDA-unmodeled retained private helpers. The first copies current label text from inferred `m_labelTextBox`, the second accepts caller-supplied text; both measure through `GrafPort::GetTextWidth`, query inherited bounds, center a 12-pixel label rectangle, clamp through `IntersectRects`, and now carry first-draft C++. |
| adjustor thunks | [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md) | Secondary and tertiary destructor thunks subtract `0xa0`/`0xa4` and forward to `0x0049b860`. |
| compiler complete-object deleting wrapper | [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md) | Exact 103-byte FALSE/non-emitting compiler wrapper. It restores vptrs, lowers the ordinary destructor, dispatches hidden bits 1/4, and conditionally releases storage; no ABI wrapper source is authored. |

## Evidence Notes

- Live IDA reports core function boundaries at `0x00495450-0x004955dc`, `0x00495620-0x0049574c`, `0x00495750-0x004957b2`, `0x004957c0-0x00495836`, `0x00495840-0x004958b6`, `0x004958c0-0x0049591f`, `0x00495920-0x00495936`, and `0x00495940-0x00495a95`, plus destructor thunks `0x0049b071-0x0049b087` and scalar deleting destructor `0x0049b860-0x0049b8c7`.
- 2026-06-07 A004 split-recheck created exact destructor-side children [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md) and [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md); the scalar deleting destructor is assigned here because the child is `86/88` and this direct class parent is `86/86`.
- The constructor has a single direct caller at `0x00518d9c` inside `0x00517f30`; no fitting-room constructor caller was observed in this pass.
- Constructor setup calls [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) construction at `0x0049548c`, writes temporary `ButtonControlPane` vtables at `0x0049549c/0x004954a2/0x004954ac`, then writes `TextButtonExControlPane` vtables at `0x004954dc/0x004954e2/0x004954ec`.
- The child text provider pointer lives at `this+0x10c`; constructor allocates `372` bytes via `0x004f4aa0`, constructs the provider through `0x00595390`, sets its rect through vtable slot `+0x2c`, calls `0x0058ea80`, and shows it through `0x005446b0`.
- Live IDA names the vtable views as `??_7TextButtonExControlPane@@6B@` at `0x00617d24`, `??_7TextButtonExControlPane@@6B@_0` at `0x00617d90`, and `??_7TextButtonExControlPane@@6B@_1` at `0x00617dc0`.
- Key slots are `0x00617d24 -> 0x0049b860`, `0x00617d54 -> 0x004958c0`, `0x00617d5c -> 0x00495920`, `0x00617d68 -> 0x00495940`, `0x00617d6c -> 0x00495620`, `0x00617d70 -> 0x004957c0`, `0x00617d74 -> 0x00495840`, `0x00617d88 -> 0x00495750`, `0x00617d90 -> 0x0049b071`, and `0x00617dc0 -> 0x0049b07c`.
- Inherited slot identities resolve the source names: `0x00495620` is `SetVisualState`, `0x004957c0/0x00495840` are `Enable/Disable`, and `0x004958c0/0x00495920` are `AddToLayer/RemoveFromLayer`. Older `SetState`, `ShowControl`/`HideControl`, and attach/detach names described behavior but did not match the source-level base contract.
- Historical pre-Gate2B evidence found no IDA function object, direct xrefs, or entrypoint pointer hits at `0x004955e0`. Gate 2B has since modeled the exact function without changing its zero-xref state; its vtable writes match the constructor and scalar destructor and retain this class ownership.
- B007's 2026-06-19 source-quality pass corrected [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md) from old endpoint `0x00495be2` to half-open `0x00495be3`: the first helper's `ret 4` occupies `0x00495b4e-0x00495b50`, internal padding is `0x00495b51-0x00495b60`, and the second helper's `ret 8` occupies `0x00495be0-0x00495be2`. The same pass found no direct branch/call, VA/RVA pointer, vtable-cell, or table route to the raw starts, so the helpers are documented as retained unreferenced private source methods.
- `SetState` uses provider text helpers `0x0058e380`, text measurement `0x004baa70`, bounds helpers `0x004b8e00`, `0x004b7cc0`, and `0x004b7e10`, then updates the provider via child slot `+0x2c` and invalidates the owner through vtable slot `+0x20`.
- `Enable` and `Disable` toggle the provider through `0x0058eb30` with values `134` and `128`, then invalidate provider/owner bounds while changing inherited `m_enabled`; this is enabled-state behavior, not Pane visibility naming.
- `OnPaint` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, loads resources through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, `0x00457a60`, and `0x004d02f0`, uses resource names at `0x006186bc`, `0x006186d8`, `0x006186ec`, and `"NP"` at `0x0061484c`, and applies the state `11` one-pixel disabled offset before drawing.
- The scalar deleting destructor releases the `+0x10c` child through its virtual destructor, calls shared pane cleanup `0x00544580`, and only calls `0x004f4ac0` when scalar delete is requested and the no-delete flag bit is clear.

## Applied IDA Analysis Reconciliation

- Only incomplete `TextButtonExControlPane` was added to IDA for pointer prototypes; no guessed flat layout was introduced. The complete source layout remains the documented `ButtonControlPane` base plus `TextBoxPane *m_labelTextBox`.
- Constructor `[0x00495450,0x004955dc)` is now `TextButtonExControlPane__Constructor` with exact signature `TextButtonExControlPane *__thiscall TextButtonExControlPane__Constructor(TextButtonExControlPane *this, const wchar_t *text, const RectBounds *bounds)`. Its exact function-repeatable comment records the three vptr views, `0x174`-byte TextBoxPane allocation, wide label text/bounds inputs, and owned store at `+0x10c`. IDA automatically materialized `text +0x50` and `bounds +0x54`; all seven prior locals and nonargument frame entries remain.
- Ordinary destructor `[0x004955e0,0x00495615)` is now exact `void __thiscall TextButtonExControlPane__Destructor(TextButtonExControlPane *this)`. Its function-repeatable comment records owned-child deletion and compiler-lowered vptr/base teardown. The authoritative sole frame entry is `__return_address +0x4`, and the authoritative auto local is `void (__thiscall ***v2)(_DWORD)`; the predicted `+0x0`/two-argument presentation was not forced.
- Complete-object wrapper `[0x0049b860,0x0049b8c7)` is now `TextButtonExControlPane__ScalarDeletingDestructor(TextButtonExControlPane *this, unsigned int flags)` with automatic persistent `flags +0xc`. The two adjusted entries are now `TextButtonExControlPane__ScalarDeletingDestructorAdjustorA0/A4(void *adjustedThis, unsigned int flags)` with automatic persistent `flags +0x4`; their exact offsets, bytes, and vtable-only routes are unchanged.
- All five exact functions carry their accepted function-repeatable comments; address and function-regular channels remain blank. Stale interior address-regular comments at `0x0049b863`, `0x0049b890`, and `0x0049b8a2` were cleared. Protected bytes, fences, successor, xrefs, UDTs, vtable/RTTI names/comments, and dependency comments/types are unchanged.
- Persisted IDB SHA256 is `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7`.

## Exact Layout And Source / Compiler Split

- Complete-object size is `0x110`. The exact [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) base occupies `[+0x000,+0x10c)`, and `TextBoxPane *m_labelTextBox` occupies `[+0x10c,+0x110)`.
- Constructor, ordinary destructor, scalar wrapper, and primary/secondary/tertiary vptr stores independently prove the same complete object and all three inherited facets.
- Human-authored class source is the complete H declaration above, authored method children, the UID0003NA one-line destructor, and the two UID0003NC `CalculateLabelRect` helper bodies.
- UID0002Y6 adjusted entries, UID0002Y7 complete-object deleting wrapper, the `[0x00617d20,0x00617dc8)` vtable/RTTI island, hidden deleting flags, and alignment bytes are compiler/linker output. They remain documentation evidence and must not appear as handwritten C++.
- The single `[[CHILDREN]]` marker remains in H after the declaration so emitted method definitions attach without putting class declarations or child bodies in the CPP channel.

## Negative Evidence And Rejected Alternatives

- No original symbols prove the private member/helper spellings or a narrower physical filename. The strongest role-based names are used instead of `sub_`, offset, or decompiler labels.
- Fitting-room/generated owner names are rejected because the constructor, all three vtables, RTTI, field lifecycle, and method slots identify the generic TextButtonEx class.
- A separate `TextButtonExControlPane.cpp` remains plausible historically but unsupported; the established [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) route is retained.
- Handwritten scalar-wrapper/adjustor/vtable code is rejected because the virtual destructor declaration and ordinary body regenerate it.

## Score Rationale

Completion is `94` because the complete `0x110` layout, base/field declaration, virtual contract, constructor, ordinary destructor source, text/state/enable/disable/layer/paint behavior, private helpers, vtable/RTTI triad, adjusted/deleting support, and final H/CPP routing are documented. Confidence is `96` because independent binary structures converge; it remains capped by unavailable original private/helper spelling, resource-label spelling, and exact historical physical file split.

## 2026-06-30 B010 Empty-Emitter Route Decision (Historical)

That pass correctly kept the established file route and gathered exact constructor/helper/wrapper evidence, but its declaration-withholding conclusion is superseded. The field type/lifetime, exact layout, inherited slot names, ordinary destructor source, and compiler/source boundary are now resolved; the class emits a complete H declaration, not a CPP placeholder.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000EJ][TextButtonControlPane](by-class/TextButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md)
- [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-07-29 B004 post-IDA reconciliation:
  - Recorded the applied incomplete class type, five exact function identities/signatures/function-repeatable comments, automatic argument-frame entries, raw-destructor bounded normalization, three cleared stale comments, protected-state readback, and saved-IDB SHA.
- 2026-07-28 B004 UID0002Y7 accepted implementation callback:
  - Raised `88/89 -> 94/96`, retained owner/emitter UID0000HY, set source position `20`, blanked CPP, and installed the complete human declaration in H with exactly one `[[CHILDREN]]`.
  - Closed the exact `0x110` layout and `TextBoxPane *m_labelTextBox` field, added the UID0003NA ordinary destructor source route, and separated authored methods from UID0002Y6/UID0002Y7/vtable/RTTI compiler support.
  - Corrected stale `SetState`, `ShowControl`/`HideControl`, and attach/detach terminology to inherited `SetVisualState`, `Enable`/`Disable`, and `AddToLayer`/`RemoveFromLayer` while preserving the underlying behavior evidence as historical context.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: text-button paint evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the reference to EPF text-button resource loading.
- 2026-06-07 A008 alias cleanup: normalized the `OnPaint` `byte_66DA97` resource branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents extended button role, constructor/state/text/show/hide/attach/paint/destructor ranges, text-provider child behavior, caller evidence, and unreliable owner-name pollution; confidence remains capped by destructor/helper owner names.
- 2026-06-04 live IDA pass:
  - Before: completion `82`, confidence `76`, reconstructable metadata blank.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md).
  - Evidence: live IDA verified exact function boundaries, constructor caller, vtable slots/writes, text-provider child lifecycle, raw ordinary teardown at `0x004955e0`, state/text/show/hide/attach/detach/paint behavior, destructor thunks, and scalar destructor flag handling; remaining uncertainty is limited to private field names, resource labels, and final text-button source split.
- 2026-06-07 A004 Batch 046 split-recheck:
  - Before: destructor/thunk evidence pointed only to the broad [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) aggregate.
  - Changed to: linked exact adjustor child [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md) and exact scalar deleting destructor child [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md).
  - Evidence: A004 read-only IDA MCP confirmed two `0x0b` adjustors, `sub_49B860` ending at `0x0049b8c7`, vtable cell `0x00617d24`, and padding `0x0049b8c7-0x0049b8d0`.
- 2026-06-21 Rule 26/B007 label-helper incorporation:
  - Before: scores were `86/86`, the class page described the `+0x10c` child mostly as a provider pointer, and the retained raw label-bounds helpers were not listed in the method table.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`, added inferred `TextBoxPane *m_labelTextBox`, documented `CalculateLabelRect` overloads at corrected [UID:0003NC][0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers](by-memory/0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md), and recorded the no-direct-branch/no-pointer reachability caveat.
  - Evidence: B007 raw PE/Capstone recheck corrected the helper endpoint/padding, verified no direct branch/call or VA/RVA pointer route to the raw starts, and tied the bodies to TextButtonEx-owned `m_labelTextBox`, `TextEditPane::CopyWideText`, `GrafPort::GetTextWidth`, inherited `GetBounds`, and `IntersectRects`.
