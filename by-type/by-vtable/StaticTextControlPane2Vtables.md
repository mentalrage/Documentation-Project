*** UID:0004L5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:120 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by the StaticTextControlPane2 declaration and virtual methods. The compiler
// regenerates the primary, secondary, and tertiary vtable views and RTTI locators.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2 Vtables

## Status

- Source-local declaration support for the three StaticTextControlPane2 vtable views and RTTI locators.
- Direct owner/emitter: [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md), position `120`; source file [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).
- Exact backing data: `0x00618600-0x006186a4`, ending before successor class RTTI/table data.

## Exact Views

| View | Locator | Vtable base | Target-specific slots |
| --- | --- | --- | --- |
| primary | `0x00618600` | `0x00618604` | scalar deleting destructor at slot 0; Show slot 5; Hide slot 6; AddToLayer slot 12; RemoveFromLayer slot 14; OnPaint slot 17; `GetControlType(int,int)` terminal slot 24 (`+0x60`). |
| secondary | `0x00618668` | `0x0061866c` | `this -= 0xa0` deleting-destructor adjustor followed by inherited secondary Pane slots. |
| tertiary | `0x00618698` | `0x0061869c` | `this -= 0xa4` deleting-destructor adjustor followed by the inherited/default tertiary slot. |

The primary terminal cell `0x00618664 -> 0x0049b910` is the exact AL-return/`ret 8` control-type override. Secondary and tertiary first cells target `0x0049b019` and `0x0049b024`.

## Lifecycle Evidence

Primary vptr stores occur at constructor `0x0049a489`, ordinary teardown `0x0049a8ba`, and scalar wrapper `0x0049b5fd`. Secondary stores occur at `0x0049a48f`, `0x0049a8c0`, and `0x0049b603`; tertiary stores occur at `0x0049a499`, `0x0049a8ca`, and `0x0049b60d`. The repeated triad proves one multiple-view class identity across construction and both teardown forms.

## Source And Compiler Disposition

The accepted class declaration, inheritance, ordinary virtual destructor, and virtual method definitions regenerate these tables, RTTI locators, deleting wrapper entries, and adjustors. The formal marker records coverage without hand-emitting dword arrays, decorated names, RTTI records, or ABI addresses.

Direct ownership by UID0000E4 is stronger than ownership by the broad read-only-data aggregate, compiler-destructor aggregate, or source file because all three views describe this exact class. Score `90/94` reflects complete view/boundary/slot/store evidence; inherited slot names and exact compiler RTTI layout remain generated rather than source-authored.

## Rejected Alternatives

- Raw vtable arrays or RTTI structs in source: rejected as compiler output.
- Ownership by UID000252 or UID00011Y: rejected because those are mixed non-emitting indexes.
- Ownership by UID0000E5: rejected because the embedded nested pane has distinct tables and B005-owned methods.

## Cross-References

- [UID:0000E4][StaticTextControlPane2](by-class/StaticTextControlPane2.md)
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md)
- [UID:000252][0x00617a38-0x00618858.ControlPaneReadOnlyData](by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md)

## Changes

- 2026-07-13 B002 accepted callback: created the exact class-owned three-view vtable page at position 120 and added the covered-by-declaration marker, slot map, lifecycle stores, and no-handwritten-ABI proof.
