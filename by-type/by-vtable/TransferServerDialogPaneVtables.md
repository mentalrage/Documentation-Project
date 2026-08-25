*** UID:0004N4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting exact three-view TransferServerDialogPane RTTI/vtable support at 0x0062e480, 0x0062e4cc, and 0x0062e4fc, with complete slot roles, shared seven-base hierarchy, lifecycle stores, virtual overrides, adjustors, and compiler-generation disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TransferServerDialogPane Vtables

## Status

- Covered class: [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md).
- Exact physical data: [UID:0004MS][0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData](by-memory/0x0062e47c-0x0062e504.TransferServerDialogPaneVtableData.md).
- Source file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md).
- Disposition: source-declared/compiler-generated binary. The class hierarchy, virtual destructor, and overrides produce these tables; this page remains blank and non-emitting.

## RTTI Views And Hierarchy

| View | COL pointer cell | Table base | Receiver offset | Role |
| --- | --- | --- | --- | --- |
| primary | `0x0062e47c -> 0x00651954` | `0x0062e480` | `0` | TransferServerDialogPane/Pane primary virtual surface |
| secondary | `0x0062e4c8 -> 0x00651a04` | `0x0062e4cc` | `+0xa0` | inherited EventHandler facet |
| tertiary | `0x0062e4f8 -> 0x00651a18` | `0x0062e4fc` | `+0xa4` | inherited TimerHandler facet |

All views share type descriptor `0x006799b0` and hierarchy descriptor `0x00651968`. The seven bases are TransferServerDialogPane, Pane, GrafPort, LObject, inherited EventHandler, inherited TimerHandler, and empty Singleton<TransferServerDialogPane> at `+0xf8`. Source direct bases remain only Pane and Singleton.

## Primary Table

| Cell | Target | Source role |
| --- | --- | --- |
| `0x0062e480` | `0x005993e0` | compiler scalar deleting destructor |
| `0x0062e484` | `0x004f4b10` | inherited LObject runtime-class accessor |
| `0x0062e488` | `0x0041b6c0` | inherited default/null virtual |
| `0x0062e48c` | `0x004b8e20` | inherited `Pane::UpdateRenderRegion` |
| `0x0062e490` | `0x0041d680` | inherited default/null virtual |
| `0x0062e494` | `0x00544730` | inherited `Pane::Show` |
| `0x0062e498` | `0x00544750` | inherited `Pane::Hide` |
| `0x0062e49c` | `0x005447a0` | inherited `Pane::Repaint` |
| `0x0062e4a0` | `0x00544800` | inherited `Pane::InvalidateRect` |
| `0x0062e4a4` | `0x00544a20` | inherited `Pane::GetDescription` |
| `0x0062e4a8` | `0x00544b80` | inherited `Pane::GetScreenBounds` |
| `0x0062e4ac` | `0x00544bd0` | inherited `Pane::SetBounds` |
| `0x0062e4b0` | `0x00544c70` | inherited `Pane::AddToLayer` |
| `0x0062e4b4` | `0x00544cb0` | inherited `Pane::InsertInLayer` |
| `0x0062e4b8` | `0x00544ce0` | inherited `Pane::RemoveFromLayer` |
| `0x0062e4bc` | `0x00544d30` | inherited pane-order dispatcher |
| `0x0062e4c0` | `0x00544d70` | inherited event-handler unregister |
| `0x0062e4c4` | `0x005992f0` | source override `OnPaint()` |

## Secondary And Tertiary Tables

- EventHandler view `[0x0062e4cc,0x0062e4f8)`: first slot `0x005993bb` is the `this -= 0xa0` destructor adjustor; remaining slots `0x00544db0`, `0x00544dd0`, `0x00544e10`, `0x00544e50`, `0x00544e70`, `0x00544eb0`, `0x00544ed0`, `0x00544ef0`, `0x00544f10`, and `0x00544f30` are inherited Pane/EventHandler behavior. This class adds no EventHandler override.
- TimerHandler view `[0x0062e4fc,0x0062e504)`: `0x005993c6` is the `this -= 0xa4` destructor adjustor and `0x00599270` is source override `OnTimer(int,int,int)`.
- The adjustors forward to primary scalar wrapper `0x005993e0`. They are compiler ABI support and remain blank exact children.

## Construction, Destruction, And Liveness

- Constructor `0x00598ed0` installs all three table bases after Pane construction and publishes the singleton.
- Ordinary destructor `0x00599220` and scalar wrapper `0x005993e0` restore/use all views during teardown; secondary routes prove exact adjustor offsets.
- `OnPaint` is live through primary cell `0x0062e4c4`; `OnTimer` is live through tertiary cell `0x0062e500` and constructor timer scheduling.
- Three exact complete-object-locator pointers and all slots lie within `[0x0062e47c,0x0062e504)` with no padding. The string child begins exactly at `0x0062e504`.

## No-Code Proof And Rejected Alternatives

- No raw table initializer, RTTI descriptor, deleting destructor, adjustor, explicit vptr store, or source-facing compiler-helper declaration is accepted.
- Rejected direct EventHandler/TimerHandler bases: their facets and inherited entries originate in Pane.
- Rejected source methods for inherited slots and historical aliases `OnPaintFrame`/`OnTimerEvent`; only accepted overrides differ from Pane.
- Rejected ownership by the read-only aggregate or resource libraries. The class declaration is the semantic source; physical pages only document generated output.

## Reconstruction Notes

- Keep `92/95`, owner `0000F7`, false, blank emitter/position/formal C++, and `Nested:0`.
- Preserve the exact slot inventory and class-source cause. Generated output must contain no handwritten vtable/RTTI/adjustor/scalar-wrapper bodies.
