*** UID:00002U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CollectionBarControlPane : public ControlPane
{
public:
    CollectionBarControlPane(unsigned char groupIndex, const RectBounds *bounds);
    virtual ~CollectionBarControlPane();

protected:
    virtual void OnDraw();

private:
    void DrawProgressLabel(const wchar_t *text, int x, int y, unsigned char fontSet);

    signed char m_totalEntries;
    signed char m_collectedEntries;
    char *m_numericGlyphs;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CollectionBarControlPane

## Status

- Likely source file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Address range: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md)
- Historical recovered class filename: `class_CollectionBarControlPane.cpp`; it is provenance rather than source-file authority.
- Confidence: strong for the complete declaration, exact children, typed collection-data view, glyph-buffer ownership, vtable routes, and unguarded percentage arithmetic.

## Class Purpose

`CollectionBarControlPane` draws the selected collection group's progress bar. It reads total/current counts from the collection data block, renders `CLTBAR` left/fill/right sprites, and draws the `current/total(percent)` label with a small bitmap font table.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionBarControlPane` | [UID:0004JR][0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor](by-memory/0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor.md) `0x0048dc30-0x0048dce0` | Constructs control type `8`, loads `9X11FONT.BIN`, and copies signed total/current counts from the typed group view. |
| `~CollectionBarControlPane` | [UID:0004JT][0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor](by-memory/0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor.md) `0x0048dce0-0x0048dd53` | Frees the glyph table and permits compiler-generated base teardown. |
| `OnDraw` | [UID:0004JU][0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw](by-memory/0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw.md) `0x0048dd60-0x0048dfec` | Draws bar fill and centered label, preserving exact unguarded `collected * 100 / total` behavior when total is zero. |
| `DrawProgressLabel` | [UID:0004JV][0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel](by-memory/0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel.md) `0x0048dff0-0x0048e133` | Draws digits/symbols using the loaded glyph table and `FONTSYMB` sprites. |
| destructor adjustors | [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md) `0x0048e14b-0x0048e18d` | Shared compiler-generated vtable adjustors; bar cells occupy the first two thunks. |
| `ScalarDeletingDestructor` | [UID:0004JY][0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor](by-memory/0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor.md) `0x0048e190-0x0048e244` | Compiler-generated deleting wrapper regenerated from the normal virtual destructor. |

## Data And Globals

- Reads [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) through `g_pUserPane->GetCollectionData()`; [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) is the historical alias for this same in-object storage, and no separate `g_collectionProgressTable` global is proven.
- Uses `g_uiSpriteManager`/EPF frame helpers for `CLTBAR` and `FONTSYMB` resources.

## Vtable Data Notes

- The `0x00616630-0x006166d4` vtable group in [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) is declaration-generated data for this private progress-bar class. The primary first slot is `CollectionBarControlPane_ScalarDeletingDestructor` at `0x0048e190`; constructor `0x0048dc30`, destructor body `0x0048dce0`, and scalar deleting destructor `0x0048e190` all share vtable views `0x00616634`, `0x0061669c`, and `0x006166cc`.
- The exact bar secondary/tertiary first slots use adjustors `0x0048e14b` and `0x0048e156`, both targeting scalar wrapper `0x0048e190`. These are compiler-generated from this declaration and normal destructor; no adjustor or raw vtable body is handwritten.

## Evidence Notes

- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms modeled class anchors `sub_48DC30` size `0xb0`, `sub_48DCE0` size `0x73`, `sub_48DD60` size `0x28c`, `sub_48DFF0` size `0x143`, and `sub_48E190` size `0xb4`.
- Constructor xrefs remain the two `CollectionDialogPane` call sites `0x0048c98a` and `0x0048cd8a`. The paint method remains vtable-only through data cell `0x00616678`, and `DrawProgressLabel` has the direct paint caller at `0x0048dfd7`.
- `analyze_component` over the five anchors reports the expected internal edge `0x0048dd60 -> 0x0048dff0`, shared class vtables `0x00616634`, `0x0061669c`, and `0x006166cc` across constructor/destructor/scalar-delete paths, and shared data `dword_67A744` in paint/label rendering.
- `xrefs_to(0x0067a748)` remains high fanout because the collection-data pointer is shared across the collection subsystem; this page only owns the progress-bar consumer behavior, while [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md) and [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md) carry the broader data-layout evidence.
- `make_signature_for_range(0x0048dc30,0x0048e243)` returns a unique wildcarded signature for the constructor/destructor/paint/label/scalar-delete span.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 90 | The complete class declaration, exact child ranges, `OnDraw` slot/name, constructor and glyph-buffer lifetime, typed count fields, label helper, destructor/compiler boundary, owner/emitter route, and zero-total division behavior are source-ready. |
| Confidence | 91 | Live xrefs, vtables, constructor callers, component summary, typed data layout, resources, and exact split agree. Original private names remain inferred, but no unresolved raw offset or helper ownership remains in emitted C++. |

## Cross-References

- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:00002V][CollectionDialogPane](by-class/CollectionDialogPane.md)
- [UID:00002W][CollectionEntryControlPane](by-class/CollectionEntryControlPane.md)
- [UID:0001R8][collection-ui-resources](by-resource/collection-ui-resources.md)
- [UID:0004JR][0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor](by-memory/0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor.md)
- [UID:0004JT][0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor](by-memory/0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor.md)
- [UID:0004JU][0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw](by-memory/0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw.md)
- [UID:0004JV][0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel](by-memory/0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel.md)
- [UID:0004JY][0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor](by-memory/0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor.md)

## Changes

- What existed before: the page documented collection progress-bar behavior, methods, resource usage, and globals, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: constructor, destructor, paint, label drawing, collection data reads, and sprite/font dependencies are documented; exact member names and final class declaration remain incomplete.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled method starts at `0x0048dc30`, `0x0048dce0`, `0x0048dd60`, `0x0048dff0`, and `0x0048e190`, with construction from `CollectionDialogPane` at `0x0048c98a` and `0x0048cd8a`.
- 2026-06-05: Raised from `78/86` to `82/86` and attached to [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).
  - Evidence: live IDA MCP confirmed constructor/destructor/paint/label/scalar-destructor starts, constructor xrefs from the dialog at `0x0048c98a` and `0x0048cd8a`, the virtual paint table reference at `0x00616678`, scalar-destructor thunk/table references, and the paint path's progress-fill and label-draw dependencies.
  - Remaining limits: exact class declaration and member names are still pending, so final C++ remains blank.
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `86/89` with no owner/emitter changes. Live IDA reconfirmed constructor/destructor/paint/label/scalar-delete sizes, the two dialog constructor call sites, vtable-only paint routing, the internal paint-to-label call, class vtable state shared by constructor/destructor wrappers, collection-data consumer scope, and a unique documented-range signature. C++ remains blank until member names and the original control declaration are source-quality.
- 2026-06-20 B001 Rule 26 read-only-data incorporation:
  - Summary/evidence: replaced the provisional `g_collectionProgressTable` wording with a typed local view over [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md), and documented that the [UID:000250][0x006164f0-0x006168d0.CollectionReadOnlyData](by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md) bar-control vtable group is generated from this private class declaration rather than emitted as raw data.
- 2026-07-13 B004 UID00010X split callback: raised from `86/89` to `90/91` and installed the complete accepted class declaration.
  - Exact closure: constructor [UID:0004JR][0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor](by-memory/0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor.md), normal destructor [UID:0004JT][0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor](by-memory/0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor.md), `OnDraw` [UID:0004JU][0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw](by-memory/0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw.md), `DrawProgressLabel` [UID:0004JV][0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel](by-memory/0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel.md), shared adjustors [UID:0004JX][0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks](by-memory/0x0048e14b-0x0048e18d.CollectionDialogControlDestructorAdjustorThunks.md), and compiler scalar wrapper [UID:0004JY][0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor](by-memory/0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor.md).
  - Preserved behavior: glyph buffer allocation/free, signed count fields, exact resource dependencies, centered label rendering, unguarded zero-total percentage division, vtable routing, source owner/emitter, and rejection of a separate progress-table global or handwritten compiler support.
