*** UID:0001TX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000021 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheckBoxControlPaneLayout

## Status

- Entity kind: non-emitting class-layout evidence for the one source declaration in UID000021 H.
- Semantic owner: [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md); standalone source route [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md).
- Source disposition: false/non-emitting with blank CPP/H. The complete declaration appears once in UID000021 H; this page documents exact offsets and must not emit a duplicate struct.
- Confidence: very strong for complete-object size, inherited ControlPane/EventHandler/TimerHandler views, target-owned fields, natural alignment, and source route.
- Evidence basis: repeated IDA MCP method/constructor/vtable/RTTI checks, exact UID0002M9 PMDs, and accepted base-class documentation. Stale generated/Wave names are not used as evidence.

## Layout

```text
CheckBoxControlPane  // observed size 0x150
  +0x000  ControlPane base / complete-object primary view
  +0x0a0  EventHandler secondary view    // constructor writes 0x00618540
  +0x0a4  TimerHandler tertiary view     // constructor writes 0x00618570
  +0x108  wchar_t m_tileName[16]         // e.g. "ONOFFBUT.EPF"
  +0x128  wchar_t m_paletteName[16]      // e.g. "BUTTON.PAL"
  +0x148  short m_checkedFrame
  +0x14a  short m_uncheckedFrame
  +0x14c  bool m_checked
  +0x14d  padding/alignment to 0x150
```

The constructor copies two 16-wide-character strings with `wcscpy_s(..., 16, ...)`. UID0002M9's PMDs independently name the `+0xA0` and `+0xA4` facets as EventHandler and TimerHandler; they are no longer unresolved generic secondary/tertiary views.

## IDA Evidence

IDA MCP `lookup_funcs` confirms the checkbox method cluster as six adjacent functions: constructor `[0x00499d40,0x00499db9)`, setter `[0x00499dc0,0x00499dd0)`, getter `[0x00499dd0,0x00499dd7)`, EventHandler-view pointer/mouse handler `[0x00499de0,0x00499e2d)`, paint `[0x00499e30,0x00499ec0)`, and `SetVisualState` `[0x00499ec0,0x00499f0e)`.

IDA decompilation confirms the constructor calls the generic control constructor with type `7`, installs the three `CheckBoxControlPane` vtables at offsets `+0x000`, `+0x0a0`, and `+0x0a4`, clears byte `this+0x14c`, copies two bounded wide strings into `this+0x108` and `this+0x128` with count `0x10`, and stores two 16-bit frame ids at `this+0x148` and `this+0x14a`.

The setter/getter access only byte `this+0x14C`. `HandlePointerOrMouseEvent` enters through the EventHandler view at complete object `+0xA0`, toggles the byte on event type `3` inside inherited `m_bounds`, invalidates, and forwards to EventHandler. `OnPaint` selects the signed 16-bit frame at `+0x148/+0x14A`, passes `+0x108` to EPF lookup, and uses `+0x128` as the palette name. `SetVisualState` accesses inherited ControlPane byte `+0x103` and bounds `+0x44`; neither offset is a CheckBox-owned field.

IDA caller checks confirm direct constructor callers at `0x00450f60`, `0x0045100d`, and `0x0047d3b4`; the setter callers are the two minimap initialization sites, and the getter caller is the mail send path at `0x0047dfd0`.

Historical C001 labels recorded constructor/accessor/OnMouse/StateTypeHelper/GetControlTypeId guesses. Current accepted names are `HandlePointerOrMouseEvent`, `SetVisualState`, and [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md); the old labels remain provenance rather than current source identity.

The 2026-07-05 B009 pass reconfirmed the offsets and callers while current IDA names were raw. UID0002M9's later complete COL/CHD/PMD reanalysis closes the inherited-view names: EventHandler `+0xA0`, TimerHandler `+0xA4`; accepted base records close inherited `m_visualState`, `m_bounds`, and `InvalidateRect` vocabulary.

## RTTI Facet Correlation

- Primary/EventHandler/TimerHandler COLs use complete-object offsets `0`, `0xA0`, and `0xA4` and share the same CheckBox type descriptor/CHD.
- CHD base order is `CheckBoxControlPane`, `ControlPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`.
- EventHandler PMD has `mdisp=0xA0`; TimerHandler PMD has `mdisp=0xA4`; both use `pdisp=-1`, `vdisp=0`, attributes `0x40`.
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) subtract exactly those offsets before reaching [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md).

## Field Semantics

`tileName` is passed to the EPF layout lookup in [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md). `paletteName` is passed as the final draw argument. Confirmed callers construct minimap and mail checkboxes with `L"ONOFFBUT.EPF"` and `L"BUTTON.PAL"`, so the second string should not be documented as a user-visible label.

`checkedFrame` and `uncheckedFrame` are selected by [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) based on the `checked` byte. [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) writes `+0x14c`; [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md) reads the same byte.

## Source-Layout Notes

`CheckBoxControlPane` is a reusable cross-feature choice control used by MiniMap and NewMail. The current source topology is settled as standalone `NexusTK/ui/controls/CheckBoxControlPane.cpp/.h`; the broader ButtonControlPane fold remains rejected historical grouping context. UID000021 H owns the exact declaration, so this evidence page stays non-emitting.

## Score Rationale

Completion `93` records the exact `0x150` size, named three-view inheritance, two bounded 16-wide-character resource buffers, frame words, checked byte, natural alignment, constructor/caller/accessor/event/paint/visual-state evidence, RTTI PMDs, source declaration owner, and historical corrections. Confidence `95` reflects direct binary/layout agreement; exact stripped private spelling remains inferred rather than symbol-proven.

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md)
- [UID:0004Y1][0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b110-0x0049b165.CheckBoxControlPaneScalarDeletingDestructor.md)
- [UID:0004Y2][0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart](by-memory/0x0049b8d0-0x0049b8d5.CheckBoxControlPaneHitTestPart.md)

## Resolved Questions And Confidence Context

- Source placement is resolved to standalone CheckBoxControlPane.cpp/.h; ButtonControlPane remains related family history, not current ownership.
- Inherited views are resolved to EventHandler at `+0xA0` and TimerHandler at `+0xA4` through exact PMDs and adjustor behavior.
- Inherited `+0x103` and `+0x20` vocabulary is resolved to `m_visualState` and `InvalidateRect` through accepted ControlPane records and `SetVisualState` behavior.
- Exact original private spelling remains unavailable. The project-consistent names in UID000021 H are the accepted human source representation rather than a blocker or reason for raw labels.

## Changes

- 2026-07-26 B002 UID0002M9 source-quality implementation:
  - Changed `85/91 -> 93/95`, retained semantic owner UID000021, and made this layout facet false/non-emitting with blank formals because UID000021 H owns the one declaration.
  - Named exact ControlPane/EventHandler/TimerHandler views at `0/+0xA0/+0xA4`, preserved all target-owned field offsets and natural tail alignment, and added full RTTI PMD correlation.
  - Corrected current method vocabulary to `HandlePointerOrMouseEvent`, `SetVisualState`, and UID0004Y2 `HitTestPart`; closed inherited state/invalidation and standalone-source questions.
  - Preserved earlier unresolved generated-label/source-fold assumptions below as historical evidence.

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile/caller checks on 2026-05-31 directly verify the field offsets used by the constructor, accessor, mouse, and paint methods; final source-file split and inherited subobject names remain below near-final confidence.

- 2026-06-06: Completion/confidence changed from `74/88` to `82/90`, and `AUTOGEN_PARENT_UID` was set to [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md).
  - Before: direct field evidence was documented, but the metadata stayed below the parent-child attachment gate and the manual by-struct coverage row still showed a stale `50%`.
  - After: the page records the parent gate, score rationale, and coverage report sync.
  - Evidence: constructor, setter/getter, mouse, paint, and state/helper evidence covers every listed field offset; the only remaining limits are inherited-view names and final source-file ownership.
- 2026-06-16 C001 IDA/name refresh:
  - Before: `82/90`, with exact offset evidence but a low completion score relative to the linked file/class pages.
  - After: `85/91`, preserving [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md) as canonical owner/emitter and final C++ blank.
  - Evidence: live IDA reconfirmed the method cluster, constructor/accessor caller sets, three vtable refs, and the unique core range signature; C001 applied and saved current method names. No type/member edits were applied because source-facing inherited-view names remain provisional and the final [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) versus [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) source split is still open.
- 2026-07-05 B009 source-quality support update:
  - Scores and metadata unchanged.
  - Added accepted source-facing field names for target-owned fields, current implementation route through `CheckBoxControlPane.cpp`, current MCP raw-label caveat, and retained caps for inherited subobject/state/refresh names.
