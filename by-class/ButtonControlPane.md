*** UID:00001E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ButtonControlPane.h"
#include "TextEditPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../../render/EPFTileContext.h"
#include "../core/ControlPane.h"

class Event;
struct RectBounds;

class ButtonControlPane : public ControlPane
{
public:
    explicit ButtonControlPane(const RectBounds &bounds)
        : ControlPane(0, &bounds)
    {
        m_controlActive = false;
        m_controlSelected = false;
        m_controlFlags = 1;
        m_handlesEnterKey = true;
        SetMode(1);
    }

    virtual ~ButtonControlPane() {}

    void SetControlSelected(bool selected);

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);

    bool m_controlSelected;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ButtonControlPane

## 2026-08-14 B003 Combined Header Closure

- CPP now includes `ButtonControlPane.h` before children. H is guarded, uses the correct render/core include paths, and keeps the complete base declaration.
- The inline constructor writes the established inherited `m_handlesEnterKey` field instead of nonexistent `m_reservedControlState`; initialization order and all other behavior remain unchanged.
- UID00006D appends ImageButtonControlPane into the same generated H. UID00001E advances from `91/93` to `92/94` for exact include/declaration and constructor-state closure.

## Status

- UID0000OJ dependency closure: CPP includes `TextEditPane.h` immediately after its own header, before children that delete or call members on the complete type. Pointer-only declarations in H remain unchanged.
- Confidence: very strong for constructor, vtable, destructor, selected-state, key/text activation, exact `0x10c` layout, and complete declaration; high for inferred original member/header spellings.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Core memory: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Autogen status: class page is source-authored/reconstructable and attached to direct file parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). Exact R8 now emits at source position `10`; it supplies the complete class declaration, inline constructor/destructor source cause, and inherited declarations needed before derived button definitions.
- Formal channel disposition: the exact accepted declaration is header source and now resides byte-for-text in `RECONSTRUCTION_H CODE`; the CPP channel is blank. No declaration text, initialization order, inline body, access level, or member detail changed during this channel correction.

## UID0000OJ Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-052 | Owning CPP includes `TextEditPane.h` after `ButtonControlPane.h`, resolving complete-type use without changing the public header. |
| C0000OJ-473 | ButtonControlPane consumer visibility is supplied through the existing UID0000ON header owner. |

## Class Purpose

`ButtonControlPane` is the base clickable button control above `ControlPane`. It installs button-specific vtables, initializes pressed/selected flags, handles selected-state redraw, and contains key-activation evidence reused by derived button classes.

[UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) treats this as the generic button/choice-control module under `ui/controls`, grouping the base button with image/text/checkbox/radio/slider/selection helpers while keeping passive progress controls and unrelated visual controls split out.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ButtonControlPane` | `0x00494eb0-0x00494f38` | Constructs the base `ControlPane`, installs three button vtables, clears button state, and initializes the `0x0101` word at `+0xff`. |
| `SetControlSelected` | `0x00494f40-0x00494f64` | Updates byte `+0x108` and invalidates/redraws the `+0x44` rectangle only when the selected state changes. |
| `HandleKeyOrTextEvent(Event *)` | `0x00494f70-0x0049500d` | Current secondary EventHandler override; accepts Space/Enter and drives the pressed/activate visual sequence. Historical `OnKeyPress` is retained only as a superseded alias. |
| retained selected-frame draw raw helper | `0x00495010-0x0049503d` | [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) checks inherited `m_enabled` at `+0x101` and selected flag `+0x108`, sets GrafPort draw color `1`, clears draw mode `+0x70`, and frames bounds `+0x44`; no formal method body is emitted because complete route/liveness evidence remains negative. |
| shared deleting entry | `0x0049b0d0-0x0049b10b` | UID0002XW is one compiler-folded entry shared with SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane. It tears down Pane, applies deleting flags, optionally frees storage, and uses `0x10c` on a one-byte no-op branch. |
| shared destructor adjustors | `0x0049af11-0x0049af27` | UID0002XV secondary and tertiary vtable adjustors subtract `0xa0` and `0xa4`, then tail-call UID0002XW; three other class families use the same pair. |

## Ownership And Layout Evidence

| Evidence area | Source | Meaning |
| --- | --- | --- |
| source module | [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) | Places the class in `NexusTK/ui/controls/ButtonControlPane.cpp`, with possible later split only if original-source evidence proves it. |
| core neighborhood | [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) | Confirms the base button methods sit inside the generic button/choice-control family, not a feature dialog. |
| vtable/read-only data | [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) | Lists `ButtonControlPane` among the generic control-pane family vtables and records representative xrefs including `sub_494EB0`. |
| destructor/thunks | [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) | The destructor/thunk band maps `ButtonControlPane`, text/image/radio/slider/check controls, and exclusions through vtable ownership instead of decompiler owner labels. |
| derived fan-in | Live IDA xrefs to `0x00494eb0` and the vtable bases | Constructor callers include generic derived controls such as image, gender, direction, and pretty buttons. |

## Exact Layout And Source Contract

The complete object is exactly `0x10c` bytes:

| Offset | Source region | Evidence and disposition |
| --- | --- | --- |
| `+0x000..+0x107` | inherited [UID:000038][ControlPane](by-class/ControlPane.md) | R7 closes the base at `0x108` and exposes the state directly written by this constructor as protected. |
| `+0x108` | `bool m_controlSelected` | Constructor clears it; `SetControlSelected` compares/writes it; retained selected-frame helper tests it. |
| `+0x109..+0x10b` | natural tail alignment | Scalar deleting wrapper uses object-size immediate `0x10c`; no source padding member is introduced. |

R8 preserves the observed constructor source-visible order after `ControlPane(0, &bounds)`: clear inherited `m_controlActive`, clear `m_controlSelected`, set inherited `m_controlFlags=1`, set inherited `m_reservedControlState=1`, then call inherited `SetMode(1)`. Direct protected access is source-faithful; private base fields, duplicate derived fields, invented setters, and raw offsets are rejected.

`ControlPane.h` is required because the base must be complete. `Event` and `RectBounds` remain pointer/reference-only and are valid forward declarations. The inline empty virtual destructor is this class's human source cause for the observed deleting entry and inherited teardown; UID0002XW is nevertheless not Button-owned because three other distinct class vtables consume the same class-neutral body. Vptr stores, deleting flags, object freeing, adjustor thunks, COMDAT/identical-code folding, EH/cookie machinery, and alignment remain compiler/linker output.

The current interface name is `HandleKeyOrTextEvent(Event *)`, matching the secondary EventHandler contract. Historical `OnKeyPress` terminology is useful search provenance only and is not emitted. The retained raw selected-frame helper remains documented but blank because its no-function/no-xref/no-call/no-pointer route proof is unchanged; its uncertainty does not block the complete class declaration.

## Boundaries And Exclusions

- `ButtonControlPane` itself is bounded inside the larger choice-control aggregate at `0x00494eb0-0x0049500d`.
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) is nearby but explicitly excluded: it owns the passive progress indicator at `0x00494c80-0x00494eaf` and should not be merged into this class just because of address locality.
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) and [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) are related button modules; they are not proof that base `ButtonControlPane` should absorb every text or pretty-button implementation.
- Some feature-specific callers reuse the base constructor, but current ownership is assigned by behavior, vtables, and broad constructor fan-in rather than caller context alone.

## Evidence Notes

- 2026-06-05 live IDA MCP audit reports method extents `sub_494EB0` `0x00494eb0-0x00494f38`, `sub_494F40` `0x00494f40-0x00494f64`, `sub_494F70` `0x00494f70-0x0049500d`, `sub_49B0D0` `0x0049b0d0-0x0049b10b`, `sub_49AF11` `0x0049af11-0x0049af1c`, and `sub_49AF1C` `0x0049af1c-0x0049af27`.
- Constructor `0x00494eb0` calls the `ControlPane` base constructor at `0x00494ede`, writes primary/secondary/tertiary `ButtonControlPane` vtables at `0x00494eee`, `0x00494ef4`, and `0x00494efe`, clears bytes at `+0x102` and `+0x108`, writes `0x0101` at `+0xff`, then calls `sub_5446B0`.
- Live IDA xrefs show 9 direct constructor references to `0x00494eb0`: modeled code callers at `0x004a220d`, four calls inside `sub_4FB630`, raw no-function code xrefs at `0x0050064d` and `0x005007ad`, plus calls from `sub_54B5E0` and `sub_54B8C0`.
- `SetControlSelected` compares the input byte with `[ecx+0x108]`, writes the byte only on change, then jumps through vtable slot `+0x20` with the rectangle/state region at `+0x44`.
- `OnKeyPress` narrows the event character through `dword_67A754`, requires event byte `[arg+4] == 8`, accepts Space or `0x0d`, adjusts from the secondary subobject by `-0xa0`, drives visual states `0x0b` and `0x0a`, refreshes through `dword_67A7CC`, sleeps `0x85` ms, then dispatches the activation through vtable slot `+0x48`.
- [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) is retained raw ButtonControlPane source-shaped code after `OnKeyPress`. Current `+0x101` meaning is inherited `ControlPane::m_enabled`; historical visible/show wording is superseded by separate Pane visibility at `+0xb4`. Selected `+0x108`, draw mode `+0x70`, bounds `+0x44`, GrafPort callees, and complete no-function/no-xref/no-call/no-pointer evidence remain unchanged.
- Inherited virtual slots `+0x4c/+0x50` are [UID:0003N3][0x00494bb0-0x00494bca.ControlPaneEnable](by-memory/0x00494bb0-0x00494bca.ControlPaneEnable.md) and [UID:0003N4][0x00494bd0-0x00494bea.ControlPaneDisable](by-memory/0x00494bd0-0x00494bea.ControlPaneDisable.md). ImageButtonControlPane overrides both; this class remains a blank/no-code route because its broader layout and destructor surface are still unresolved, not because enabled-state semantics are unknown.
- The ButtonControlPane vtable block has RTTI at `0x00617bd4`, primary destructor slot `0x00617bd8 -> sub_49B0D0`, secondary adjustor `0x00617c40 -> sub_49AF11`, key handler slot `0x00617c48 -> sub_494F70`, and tertiary adjustor `0x00617c70 -> sub_49AF1C`. Select, Weather, and Rain have their own named RTTI/vtables but point to these same three compiler entries.
- The three vtable bases are written by the base constructor and by derived constructors at `sub_495040`, applied exact `TextButtonExControlPane__Constructor` `0x00495450`, and `sub_495BF0`, supporting reuse during derived construction rather than assigning those derived owners to the base method.
- UID0002Y7 supervisor Gate 2B added only incomplete `TextButtonExControlPane`, then applied exact constructor signature `TextButtonExControlPane *__thiscall TextButtonExControlPane__Constructor(TextButtonExControlPane *this, const wchar_t *text, const RectBounds *bounds)` with automatic `text +0x50` and `bounds +0x54` frame entries and the exact source-role function-repeatable comment. The related ordinary destructor, scalar wrapper, and two adjustors were also named/typed/commented without changing ButtonControlPane bytes, ranges, xrefs, UDTs, or source declaration. Saved IDB SHA256 is `408F73923C6BDD17931E828365DC0D7D67F583FE6F0FDDA50103F45FB84461A7`.
- Xrefs to `sub_494F70` are vtable/data references at `0x0060e048`, `0x00617c48`, `0x00617cf0`, `0x00617d98`, `0x00617e3c`, `0x0061dc00`, `0x0061dca4`, `0x00622348`, and `0x006223ec`, showing the same key handler is shared by several button-derived vtables.
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md) records a 2026-06-01 boundary audit that keeps `0x00494eb0-0x0049500d` as the base button helper band.
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) records destructor/thunk ownership by vtable data.
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md) records the broader control-family vtable island that includes `ButtonControlPane`.
- 2026-06-07 A001 Batch081 live IDA recheck reconfirmed method sizes `0x88`, `0x24`, `0x9d`, `0x3b`, `0xb`, and `0xb` for the constructor, selected setter, key handler, deleting destructor, and two adjustors; `callers` currently models seven constructor callers while `xrefs_to` retains the two raw no-function constructor xrefs above, so the older nine-reference constructor fan-in remains valid when raw code refs are counted.
- 2026-06-07 A001 Batch081 parent-gate check: direct parent [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is `86/88`, documents this generic button/choice-control source family, and is the narrow direct owner for the class. The child now clears the strict `85/85` gate with final source C++ still withheld below the `95/95` reconstruction-code gate.

## UID0002XW Shared Compiler-Entry Relationship

- Button primary slot `0x00617bd8` is one of four direct references to [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md); the other primary slots belong to SelectBox, Weather, and Rain.
- Button adjusted slots `0x00617c40` and `0x00617c70` are two of eight references to [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md).
- The 59-byte target performs no `m_controlSelected` access, vptr restore, or Button-specific cleanup. It always tears down Pane, conditionally calls operator delete for bit 1, and sends `this` plus `0x10c` to a one-byte no-op helper for bit 4.
- The existing inline empty virtual destructor remains the correct human source for Button. It is one source cause of a shared compiler/linker body, not ownership evidence for that binary page.
- Best explanation is COMDAT/identical-code folding of equivalent deleting entries. Do not emit UID0002XW or UID0002XV from this class/file route, and do not add hidden deleting-flags ABI declarations to the formal class source.

## 2026-06-30 B010 Empty-Emitter Route Decision (Historical)

The pre-callback formal block was a marker-only no-code comment. The accepted B010 generated-route audit found no then-current generated direct child emitters under [UID:00001E] and correctly preserved the raw selected-frame helper's no-route status. The UID0004EL callback supersedes only the incomplete-class conclusion: R7 now closes the inherited base, R8 closes the exact `0x10c` layout and current EventHandler signature, and the inline constructor/destructor plus declarations are source-ready. The raw helper still does not gain a speculative body.

The historical `85/88 -> 87/89` move remains useful provenance for that earlier marker disposition. Current accepted metadata is `91/93` with exact R8.

## Open Questions

- Exact original spelling of `m_controlSelected` remains inferred, but offset, width, lifecycle, and source declaration are closed.
- The retained selected-frame helper at `0x00495010` has strong ButtonControlPane ownership and source behavior but no caller/vtable/table route; it remains a prose-only source-shaped helper and does not add a declaration/body to R8.
- Exact original header split between base `ButtonControlPane.cpp` and specialized button modules remains partly provisional, while the current file route is sufficient for R8.

## Score Rationale

Completion is `91` because R8 now closes the exact inheritance, `0x10c` layout, inline constructor/destructor, selected member, selected setter, and current key/text override while preserving vtable, destructor/thunk, raw-helper, caller, and family-split evidence.

Confidence is `93` because allocation size, constructor stores, selected-state reader/writer, deleting-wrapper size, vtable cells, EventHandler slot sharing, and the complete R7 base contract converge on the declaration. It remains capped by inferred original member spelling and exact original header organization.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-07-29 B004 post-IDA reconciliation: updated the TextButtonEx derived-constructor identity to its applied exact name/signature/frame state and recorded the protected family action and saved-IDB SHA; base source/formals and metadata remain unchanged.
- 2026-07-28 B004 UID0002Y7 support-channel correction:
  - Moved the complete accepted `ButtonControlPane` declaration byte-for-text from CPP to H and left CPP blank so [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md) has its source-level base declaration in the generated header.
  - Preserved metadata, scores, source position, include/forward declarations, inline constructor/destructor, selected-state API, protected event override, field spelling, and all prior evidence without behavioral change.
- 2026-07-23 B002 UID0002XW source-quality callback:
  - Score, owner/emitter, source position, `0x10c` layout, and exact class formal unchanged.
  - Recorded UID0002XW as a shared folded deleting entry caused in part by the existing explicit empty virtual destructor, not a Button-owned binary body.
  - Added exact primary/adjusted route, no-class-specific-work, bit-4 no-op, compiler/source split, and no-handwritten-ABI evidence.
- 2026-07-16 B003 UID0004EL support implementation:
  - Raised `87/89 -> 91/93`, retained owner/emitter/file route and reconstructable state, and set source position `10`.
  - Replaced the historical marker-only formal with exact R8: complete `ControlPane` include, pointer/reference-safe `Event` and `RectBounds` declarations, exact inline constructor order, inline empty virtual destructor, `SetControlSelected(bool)`, protected `HandleKeyOrTextEvent(Event *)`, and one `m_controlSelected` byte.
  - Added the exact `0x10c` layout with natural tail alignment, direct protected-access proof, current EventHandler naming, source/compiler split, and rejection of duplicate fields, invented setters, raw offsets, and handwritten ABI/vtable glue.
  - Preserved every derived-family, vtable, raw-helper, caller, source-split, negative, and historical fact; the raw selected-frame helper remains blank under its exact no-route proof.

- 2026-07-13 B005 UID0004BP support synchronization:
  - Preserved `87/89`, owner/emitter, formal no-code route, method inventory, raw liveness negatives, and all unrelated layout/destructor blockers.
  - Corrected inherited `+0x101` to `m_enabled`, linked UID0003N3/UID0003N4 Enable/Disable, and labeled earlier visible/show wording superseded without changing UID0003N8's blank formal disposition.

- What existed before: the page documented the base button role, methods, and owner-pollution caveat, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `66/76`.
- Summary and evidence: constructor, selected-state update, key activation, and derived-constructor xrefs are covered; final helper names, event semantics, and class layout remain only partially documented.
- 2026-06-02 documentation expansion:
  - What existed before: the class page lagged the stronger file and memory pages, with only a compact method list and owner-pollution note.
  - Changed to: scores `72/82`, plus source-module placement, autogen status, ownership/layout evidence table, boundary/exclusion notes, vtable/read-only data evidence, destructor/thunk evidence, and explicit open questions.
  - Summary/evidence: existing documentation ties the base class to `NexusTK/ui/controls/ButtonControlPane.cpp`, the `ButtonChoiceControlCore` method neighborhood, the control-pane vtable island, and the destructor/thunk band. C++ and `RECONSTRUCTABLE` remain blank because the source-quality class declaration and exact field names are not final.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores and still relied on broad aggregate evidence, stale owner-pollution notes, and incomplete destructor-slot detail.
  - Changed to: scores `82/86`, exact live IDA method extents, constructor/vtable writes, selected-state and key-activation behavior, primary destructor and adjustor evidence, and vtable/data xrefs.
  - Summary/evidence: completion increased because the documented behavioral surface now covers constructor, state update, key activation, destructor, adjustors, vtable slots, and caller fan-in. Confidence increased because those claims are backed by live IDA MCP disassembly/xrefs rather than stale aggregate notes. C++ and `RECONSTRUCTABLE` remain blank because source-quality field names, inheritance declaration, and final source split are still below the reconstruction gate.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE` and updated the autogen-status note to separate reconstructability from emitted C++ readiness. Current IDA MCP `lookup_funcs` reconfirmed the constructor/state/key/destructor/adjustor starts at `0x00494eb0`, `0x00494f40`, `0x00494f70`, `0x0049b0d0`, `0x0049af11`, and `0x0049af1c`, and `callers` shows broad derived-control fan-in. `AUTOGEN_PARENT_UID` remains blank because [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is still below the 80+ completion attachment gate.
- 2026-06-07 A001 Batch081 strict parent-gate update:
  - What existed before: `82/86`, reconstructable, but unassigned due stale parent-gate text from the older 80/80 rule.
  - Changed to: `85/88` and `AUTOGEN_PARENT_UID:0000HY`.
  - Summary/evidence: live IDA reconfirmed the exact method sizes, modeled/raw constructor xrefs, vtable data refs, and destructor/adjustor boundaries; [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is already `86/88` and directly owns the generic button/choice-control source module. Final C++ stays blank pending source-quality class layout and field names.
- 2026-06-21 B010 selected-frame helper incorporation (historical field terminology superseded above):
  - Scores unchanged at `85/88`.
  - Evidence: added UID0003N8 as a retained raw selected-frame helper. That pass called `+0x101` inherited visibility; the current correction supersedes only that name with `m_enabled`. Selected state, draw mode, GrafPort callees, and blank no-route formal disposition remain valid.
- 2026-06-30 B010 empty-emitter implementation:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:89`, and a formal no-code route comment in `RECONSTRUCTION_CPP CODE`.
  - Evidence: accepted B010 report preserves the base button/source-family role while rejecting a speculative full class declaration. No `[[CHILDREN]]` marker is used because current generated output has no active direct child emitters under [UID:00001E]; the exact children in the accepted ButtonControlPane family route through sibling class pages or exact memory pages.
