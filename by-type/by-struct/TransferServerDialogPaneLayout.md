*** UID:0004N3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting exact 0x100 TransferServerDialogPane layout support: Pane/GrafPort through +0xf7, inherited m_alpha at +0x90, EventHandler/TimerHandler facets at +0xa0/+0xa4, empty Singleton EBO at +0xf8, and only m_currentFrame/m_frameCount at +0xf8/+0xfc. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TransferServerDialogPane Layout

## Status

- Covered class: [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md).
- Source file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md).
- Exact allocation/object size: `0x100` bytes.
- Disposition: source-declaration support, false/non-emitting. The class declaration supplies bases and fields; this page must not emit an overlay structure or static assertions.

## Exact Layout

| Offset / span | Source identity | Evidence |
| --- | --- | --- |
| `+0x000..+0x0f7` | `Pane` base | Pane's established derived boundary is `+0xf8`; constructor begins with `Pane(3)` and destructor uses Pane teardown. |
| `+0x090` | inherited `GrafPort::m_alpha` | Constructor writes `0.9f`; reset writes `0.0f`; timer reads/subtracts/stores fade state. Independent GrafPort evidence proves the field. |
| `+0x0a0` | inherited EventHandler secondary facet | Secondary vtable view and destructor adjustor subtract exactly `0xa0`. |
| `+0x0a4` | inherited TimerHandler tertiary facet | Timer vtable view and destructor adjustor subtract exactly `0xa4`; constructor schedules through this facet. |
| `+0x0f8` | empty `Singleton<TransferServerDialogPane>` base by EBO, overlapping `int m_currentFrame` | RTTI hierarchy places Singleton at `+0xf8`; constructor writes frame index 0 and timer advances it. Empty-base overlap is ABI-correct. |
| `+0x0fc` | `int m_frameCount` | Constructor writes 34; timer uses it as modulo divisor. |
| `+0x100` | end of most-derived object | Every direct caller allocates/constructs a `0x100` object; no later field access exists. |

## RTTI And Vtable Corroboration

- All three complete-object locators share the seven-base hierarchy: TransferServerDialogPane, Pane, GrafPort, LObject, inherited EventHandler facet, inherited TimerHandler facet, and Singleton.
- The source direct bases are only `Pane` and `Singleton<TransferServerDialogPane>`. EventHandler and TimerHandler are inherited through Pane and must not be duplicated in the declaration.
- Constructor/destructor stores at object offsets `0`, `+0xa0`, and `+0xa4` match primary/secondary/tertiary vtable views.
- Adjustor thunks at `0x005993bb` and `0x005993c6` independently prove secondary receiver offsets `0xa0` and `0xa4`.

## Method-Use Corroboration

- Constructor `0x00598ed0` initializes both owned fields and inherited alpha; nine callers allocate the exact object size.
- Reset `0x00599250` touches only inherited alpha and pane invalidation.
- `OnTimer` receives the TimerHandler facet and maps callback-relative `-0x14`, `+0x54`, and `+0x58` back to primary `+0x90`, `+0xf8`, and `+0xfc`.
- `OnPaint` reads `m_currentFrame` for the selected TRANSSVR frame. No source method accesses any additional derived field.

## Rejected Alternatives And Historical Assumptions

- Rejected three direct bases `Pane, EventHandler, TimerHandler`: Pane already supplies handler facets; duplicating them breaks RTTI and offsets.
- Rejected a stored Singleton pointer/byte at `+0xf8`: Singleton is empty and overlaps `m_currentFrame` through EBO; singleton state lives in global storage.
- Rejected moving alpha into the derived class or naming it a raw fade dword: independent GrafPort layout and cross-family use prove inherited `m_alpha`.
- Rejected fields for autoClose, asset package, frame bounds, map pane, palette, or tile context: those are constructor parameters/locals/globals, not object storage.
- Historical raw `int*`/dword indexing and medium-confidence field names are superseded by the consistent typed layout.

## Reconstruction Notes

- Keep this support page `91/94`, owner `0000F7`, false, blank emitter/position/formal C++, and `Nested:0`.
- The accepted class block must declare only `int m_currentFrame;` and `int m_frameCount;` after the two direct bases.
- Preserve EBO overlap as an ABI observation, not an explicit union, padding member, or source annotation.
