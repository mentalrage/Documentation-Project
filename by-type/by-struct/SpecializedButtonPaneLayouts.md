*** UID:0001W7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpecializedButtonPane Layouts

## Status

- Confidence: very strong for observed offsets, sizes, inherited facets, and field roles. Human declarations emit once through their class H pages; this aggregate layout page is evidence-only and false/non-emitting.
- Likely owner headers: `ui/controls/DirectionButtonControlPane.h`, `ui/controls/GenderButtonControlPane.h`, and `ui/controls/CheckBoxTextControlPane.h`, or a shared specialized-button header.
- Primary file doc: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Vtable doc: [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Shared Base Shape

These controls use the same multiple-vtable `ControlPane`/`ButtonControlPane` shape seen across pane controls:

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | primary vtable pointer | Constructors/inline setup and scalar deleting destructors install concrete class vtables. |
| `0xa0` | secondary vtable pointer | Inline setup and destructors write the class secondary vtable. |
| `0xa4` | tertiary vtable pointer | Inline setup and destructors write the class tertiary vtable. |
| `0x44` | bounds/draw rect subobject | Paint methods copy an OWORD from `this + 0x44` before drawing frames. |
| `0x101` | enabled/pressed byte | Paint paths test byte `+0x101` before drawing disabled overlay. |
| `0x103` | visual state byte | State methods compare this byte against the incoming state before updating subclass frame state. |

The exact inherited names should stay with [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and `ControlPane`; this page only records subclass-specific fields.

## DirectionButtonControlPane

Observed object allocation in `NewUserMiscDialogPane` is exactly `0x114` bytes. `ButtonControlPane` occupies the single source base at offset zero with exact size `0x10c`; Direction contributes two four-byte integer fields.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x10c` | `int m_directionIndex` | Raw constructor-shaped bytes store the first stack argument here; inline `NewUserMiscDialogPane` setup writes `0` for one direction button and `1` for the other. `OnPaint` uses this as `2 * m_directionIndex` in the `DIREC.EPD` frame index. `m_frameIndex` is too broad because `+0x110` contributes the state frame, and `m_isLeft` is too narrow because the field is multiplied rather than tested as a boolean. |
| `0x110` | `int m_stateFrameOffset` | Raw constructor-shaped bytes and both inline setup consumers clear it. `SetVisualState` writes `1` when incoming state is `0x0b` and `0` otherwise; `OnPaint` adds it to `2 * m_directionIndex`. `m_visualStateFrameOffset` is the superseded verbose alias, `m_enabled` is rejected because this is an integer frame offset, and `m_pressed` is too specific for the observed state mapping. |

The exact complete-object size is `0x114`: `ButtonControlPane` `[0x000,0x10c)`, `int m_directionIndex` `[0x10c,0x110)`, and `int m_stateFrameOffset` `[0x110,0x114)`. RTTI PMDs place inherited EventHandler and TimerHandler views at complete-object offsets `+0xa0` and `+0xa4`; these are implementation facets already inherited through `ButtonControlPane`, not additional direct source bases. The one human declaration emits through [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md), with exact source children [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md), [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md), and [UID:00050I][0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint](by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md). This aggregate layout page remains evidence-only and does not duplicate the class declaration.

## GenderButtonControlPane

Observed object allocation in `NewUserMiscDialogPane` is `0x118` bytes.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x10c` | `m_genderIndex` | Inline setup writes `0` for one gender option and `1` for the other; the raw constructor stores its first argument here. `OnPaint` uses `3 * m_genderIndex` in the `GENDER.EPF` frame group. |
| `0x110` | `m_stateFrameOffset` / `m_visualStateFrameOffset` | Inline setup writes `2` for the first/default option and `0` for the second; the raw constructor stores its second argument here. `SetState` writes `1` when incoming state is `0x0b`; `OnPaint` adds it to `3 * m_genderIndex`. |
| `0x114` | `bool m_selected` | Constructor and two inlined constructor consumers initialize it, [UID:0004ZW][0x00500690-0x00500697.GenderButtonControlPaneIsSelected](by-memory/0x00500690-0x00500697.GenderButtonControlPaneIsSelected.md) returns it, and [UID:0004ZX][0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected](by-memory/0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected.md) plus NewUser command cases 3/4 mutate it. This supersedes the historical default-only name. |

The exact complete-object size is `0x118`. The source base is `ButtonControlPane` at offset zero; RTTI PMDs place inherited EventHandler and TimerHandler views at complete-object offsets `+0xa0` and `+0xa4`, so they must not be repeated as direct source bases. The one human declaration and these three fields are emitted by [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md), not duplicated by this aggregate layout page.

## CheckBoxTextControlPane

Observed allocations in UserList and PartySearch construction paths are exactly `0x30c` bytes. `ControlPane` is the sole direct source base and occupies `[0x000,0x108)`; inherited EventHandler and TimerHandler views already reside at complete-object offsets `+0xa0` and `+0xa4` and must not be repeated as direct bases.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x108` | `bool m_checked` | Constructor-shaped bytes store the initial checked flag, [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) writes the caller-supplied bool/byte, [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md) returns it, `PartySearchEditPane::OnAction` reads/toggles it directly, and `OnPaint` selects the on/off tile using it. |
| `0x109` | natural compiler alignment | One byte aligns the following wide-character array. This is not a named or explicit source member. |
| `0x10a` | `wchar_t m_label[0x100]` | Constructor-shaped bytes copy the label with a 256-wide-character count. `OnPaint` scans and draws the string from this offset twice for shadow/foreground text. |

The exact complete-object size is `0x30c`: `ControlPane [0x000,0x108)`, `bool m_checked [0x108,0x109)`, natural alignment `[0x109,0x10a)`, and `wchar_t m_label[256] [0x10a,0x30a)` plus the compiler's final natural alignment through `0x30c`. Allocation size, bounded wide copy, constructor/paint/getter/setter access, and RTTI independently agree. The source declaration uses no explicit padding field and includes a size assertion.

Historical pre-UID0002OX interpretation treated `0x004214c0` as a constant control-type helper. Exact `retn 8` ABI, terminal primary-slot parity, and twelve folded-vtable references supersede that identity with `unsigned char HitTestPart(int,int)` returning part code `22`; it is unrelated to the checked-state field.

## Evidence

- 2026-05-26 IDA MCP decompilation of `0x004fb630` shows `NewUserMiscDialogPane::NewUserMiscDialogPane` allocating `0x118`-byte gender controls and `0x114`-byte direction controls, then writing the concrete vtables and subclass fields listed above.
- 2026-05-26 IDA MCP decompilation of `0x005006d0`, `0x00500700`, `0x005007f0`, and `0x00500820` confirms the state and paint field usage for gender/direction buttons.
- 2026-05-26 IDA MCP decompilation of `0x0059df50` confirms `CheckBoxTextControlPane` reads checked byte `+0x108` and label buffer `+0x10a` during paint.
- 2026-05-31 IDA MCP recheck confirmed the same function boundaries and field accesses: `0x005006d0` writes `+0x110` when state `0x0b` arrives, `0x00500700` reads `+0x10c/+0x110` for the gender frame index, `0x005007f0` writes `+0x110` from state `0x0b`, `0x00500820` reads `+0x10c/+0x110` for the `DIREC.EPD` frame index, `0x0059df50` reads the checkbox byte and label buffer, and `0x004214c0` returns constant control type `0x16`.
- 2026-06-06 IDA MCP recheck reconfirmed the gender/direction layout evidence from the class pages: `0x00500640` and `0x005007a0` remain raw `NOFUNC` constructor-shaped starts with no entry xrefs/callers, but vtable store refs from those raw bodies and from inline `NewUserMiscDialogPane` setup still target `0x0061db90` and `0x0061dc34`. The modeled state/paint methods remain `0x005006d0`/`0x00500700` for gender and `0x005007f0`/`0x00500820` for direction, with the state methods delegating through `0x00494b80` and paint methods using the resource/render helper family.
- 2026-06-11 A005 Batch145 IDA MCP audit reconfirmed the layout-specific field uses and vtable backing. Gender state/paint at `0x005006d0`/`0x00500700` write/read `+0x110` and combine `+0x10c` as `visualState + 3 * genderIndex`; direction state/paint at `0x005007f0`/`0x00500820` write/read `+0x110` and combine `+0x10c` as `visualState + 2 * directionIndex`; checkbox paint at `0x0059df50` reads checked byte `+0x108` and label buffer `+0x10a`; checkbox destructor at `0x0059f050` resets the concrete vtables and delegates cleanup; `0x004214c0` still returns constant type `0x16`. Vtable data refs to `0x0061db90`, `0x0061dc34`, and `0x0062e99c` tie the fields to the three reusable controls, while raw constructor starts remain non-function caveats.
- 2026-06-16 C001 live IDA refresh rechecked the same blockers in session `b001_selflookpane_0001H7_20260616` after [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) reached `86/88`. `lookup_funcs` still reports raw constructor-shaped starts `0x00500640`, `0x005007a0`, `0x0059ded0`, and raw setter start `0x0059e0b0` as `Not a function`; `xrefs_to` for those four addresses still returns zero refs, so creating functions or claiming standalone handwritten constructors remains unsafe. The modeled method bodies remain exact functions: `GenderButtonControlPaneSetState` writes `+0x110` from state `0x0b`; `GenderButtonControlPaneOnPaint` reads `+0x10c/+0x110` for `visualState + 3 * genderIndex`; `DirectionButtonControlPaneSetState` writes `+0x110` from state `0x0b`; `DirectionButtonControlPaneOnPaint` reads `+0x10c/+0x110` for `visualState + 2 * directionIndex`; `CheckBoxTextControlPaneTeardownHelper` and `CheckBoxTextControlPaneScalarDeletingDestructor` reset the three concrete vtable views; `CheckBoxTextControlPaneOnPaint` reads checked byte `+0x108` and label buffer `+0x10a`; `CheckBoxTextControlPaneGetChecked` returns byte `+0x108`; and `CheckBoxTextControlPaneGetControlType` returns constant `0x16`. `xrefs_to 0x0061db90`, `0x0061dc34`, and `0x0062e99c` reconfirm inline setup/destructor/teardown vtable stores for gender, direction, and checkbox controls. Safe IDA labels were applied and saved for the modeled state/paint/destructor/teardown/type/getter helpers. Skipped IDA edits: raw function creation, struct/member declarations, prototypes, and final inherited field names remain unsafe because constructor reachability and final source split are still unresolved.
- 2026-06-20 B002 local PE reanalysis corrected the Gender resource string and field-name direction: UTF-16 `GENDER.EPF` exists at `0x0061e528`, while `GENDERBT.EPF` has zero ASCII/UTF-16 hits; `0x00500640` and `0x00500690` still have zero VA/RVA/direct-branch routes; inline `NewUserMiscDialogPane` setup writes gender option values `(m_genderIndex=0, m_stateFrameOffset=2, m_defaultSelected=1)` and `(m_genderIndex=1, m_stateFrameOffset=0, m_defaultSelected=0)`. These facts support `m_genderIndex`, `m_stateFrameOffset`, and inferred `m_defaultSelected`, but not final struct/member declarations or raw function creation.
- 2026-06-20 B004 local PE reanalysis confirms the Direction field names and raw-route caveat: `0x005007a0` has zero VA/RVA/direct-branch route but stores the first stack argument at `+0x10c`, installs the Direction vtables, clears `+0x110`, and returns `ret 8`; `0x005007f0` writes `+0x110` from state value `0x0b`; `0x00500820` computes `+0x110 + 2 * +0x10c` for the UTF-16 `DIREC.EPD` frame; and inline `NewUserMiscDialogPane` setup writes Direction instances with `m_directionIndex=0/1` and `m_stateFrameOffset=0`. These facts support `m_directionIndex` and `m_stateFrameOffset`, while inherited fields `+0x44`, `+0x101`, and `+0x103` remain base-layout names rather than Direction-owned members.
- 2026-06-21 B009 local PE/source-quality reanalysis confirms `0x0059e0b0-0x0059e0c0` is a raw no-route `CheckBoxTextControlPane::SetChecked(bool)` setter that stores `[ebp+8]` into `+0x108` and returns with `ret 4`. Combined with constructor storage, getter return, paint tile selection, and PartySearch direct toggling, this supports `bool m_checked` over generic `checked byte`, `m_state`, `m_selected`, or PartySearch-specific field names.
- 2026-08-01 B005 exact Gender reanalysis adds the omitted setter `[0x005006a0,0x005006cc)`, exact retained-inline constructor/getter/setter children, and live NewUser mutation equivalence. This resolves the old raw-start/default-only caveat for Gender without changing the independently documented Direction or CheckBox layouts.

## Assignment Gate

- Semantic owner: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md); this physical layout aggregate is false/non-emitting.
- The evidence gate is `95/97` with exact subclass offsets, all three sizes/facets, live behavior, and one-declaration routing.
- Formal code remains blank to prevent duplicate declarations. Gender emits through UID00005P, Direction through UID00003X, and CheckBox through UID000022.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 95 | Offset-level layouts for all three controls, exact sizes/direct bases/inherited facets/fields, live method consumers, vtable backing, source owners, historical alternatives, and false/non-emitting one-declaration policy are documented. |
| Confidence | 97 | Field offsets, natural alignment, sizes, and roles are instruction/RTTI/allocation-backed; retained-inline source liveness is resolved. Only original lexical spellings and source filename splits remain inferred. |
| Parent | `0000NY` | [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is the direct reusable-control source bucket and now passes the strict parent gate. |

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md)
- [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md)

## Changes

- 2026-08-17 B001 UID0002OX accepted implementation callback: raised `93/95 -> 95/97` and completed the CheckBox layout as one `0x108` ControlPane source base, `bool m_checked` at `+0x108`, natural alignment at `+0x109`, `wchar_t m_label[256]` at `+0x10a`, and exact total size `0x30c`. Added inherited `+0xa0/+0xa4` facet evidence, rejected explicit padding/direct-base duplication, corrected the historical terminal virtual to `HitTestPart(int,int)`, and retained this aggregate as false/non-emitting because UID000022 owns the declaration.

- 2026-08-05 B004 UID0002OW accepted callback: completed the Direction layout as one `0x10c` ButtonControlPane source base plus `int m_directionIndex` and `int m_stateFrameOffset` at `+0x10c/+0x110`, documented the `0x114` size and inherited `+0xa0/+0xa4` facets, linked all three exact source children, and preserved `93/95` false/non-emitting metadata.
- 2026-08-01 B005 UID0002OV accepted callback: raised to `93/95`, changed the aggregate layout page to false/non-emitting, corrected Gender `+0x114` to mutable `m_selected`, added exact `0x118` size and inherited facet PMDs, linked exact method children, and established one declaration through UID00005P while preserving sibling/history evidence.

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing IDA-backed layout notes. Changed to `COMPLETION:72`, `CONFIDENCE:82`, and `RECONSTRUCTABLE:TRUE` after rechecking the key layout offsets and helper behavior in IDA MCP. The score remains below the final-source threshold because constructor-shaped ranges for some controls are still not clean IDA function starts and final original field/type names remain partly inferred.
- 2026-06-06: Raised score to `78/84` after refreshing the gender/direction evidence while updating the related class pages. Live IDA MCP still leaves both constructor starts raw/no-xref, but it reconfirms the modeled state/paint/destructor functions, vtable refs, inline setup stores, and resource/render/base-handler callees that support the documented subclass offsets. Final source field names, inherited base layout names, and whether the raw constructor bodies should become standalone source members remain open.
- 2026-06-11: Raised to `85/86` and assigned to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) after A005 Batch145 live IDA MCP reconfirmed the three specialized-control field layouts, concrete vtable data refs, inline setup stores, state/paint/destructor/type-helper behavior, direct parent path, and raw constructor caveats. C++ remains blank until final source declarations and inherited field names are resolved.
- 2026-06-16 C001 type/layout refresh:
  - Before: the page was `85/86` and already assigned, but the source-quality blockers needed current raw-start/xref review and current IDA labels.
  - After: raised to `86/88`, refreshed the raw constructor/no-xref evidence, recorded current modeled helper behavior, updated the parent score reference, and saved safe function labels for the modeled gender/direction/checkbox helpers.
  - Evidence: live `lookup_funcs`, `xrefs_to`, and decompilation reconfirmed the exact field offsets and raw-start blockers; `rename` dry-run accepted 11 specialized-button helper labels and `idb_save` succeeded. No final C++ or type/member edits were made because constructor reachability, inherited field names, and final source split are still unresolved.
- 2026-06-20 B002 Rule 26 incorporation: corrected Gender resource wording to `GENDER.EPF`, updated Gender layout fields to `m_genderIndex`, `m_stateFrameOffset`, and inferred `m_defaultSelected`, recorded local PE no-route checks for the constructor/accessor, and preserved the no-final-member-declaration caveat until constructor reachability and inherited base layout are source-quality.
- 2026-06-20 B004 Rule 26 incorporation: updated Direction layout fields to `m_directionIndex` and `m_stateFrameOffset`/`m_visualStateFrameOffset`, recorded the no-route constructor-shaped body, state override, paint-frame computation, inline setup values, and rejected overbroad/narrow field names while preserving inherited field ownership with ControlPane/ButtonControlPane.
- 2026-06-21 Rule 26 B009 incorporation: kept score at `86/88` and refined the CheckBox layout fields to `bool m_checked` at `+0x108` and `wchar_t m_label[0x100]` at `+0x10a`, with SetChecked/GetChecked/paint/constructor/PartySearch evidence and rejected generic or consumer-specific field names.
