*** UID:00034V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00006B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:100 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004cfda0-0x004cfdff IconsPane Scalar Deleting Destructor

## Status

- Entity kind: `IconsPane` scalar deleting destructor body.
- Direct owner: [UID:00006B][IconsPane](by-class/IconsPane.md).
- Source file: [UID:0000JZ][IconsPane](by-file/IconsPane.md).
- Parent aggregate: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md).
- Rebuild handling: reconstructable class teardown semantics; final C++ stays blank below the 95+ source gate.

## Behavior

The destructor body restores the three `IconsPane` vtable views, clears [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) / `0x0069b41c`, calls shared pane cleanup at `0x00544580`, and conditionally frees `this` through `0x004f4ac0` when scalar-delete flags allow it.

IDA decompilation shows:

```c
*this = IconsPane::vftable;
this[40] = IconsPane::vftable_0;
this[41] = IconsPane::vftable_1;
dword_69B41C = 0;
sub_544580(this);
if ((flags & 1) != 0 && (flags & 4) == 0) sub_4F4AC0(this);
```

## IDA Evidence

- `py_eval` on 2026-06-10 reports IDA function `sub_4CFDA0` at `0x004cfda0-0x004cfdff`, size `0x5f`, 29 instructions, and 5 basic blocks.
- `xrefs_to 0x004cfda0` reports code refs from the two `IconsPane` adjustor thunks and a primary vtable/data ref at `0x0061b448`.
- Callees are shared pane cleanup `0x00544580`, delete helper `0x004f4ac0`, and guard helper `0x0041b6a0`.
- Vtable refs are to `0x0061b448`, `0x0061b494`, and `0x0061b4c4`; those same vtables are installed by `IconsPane` constructor/cleanup at `0x004cf1f0` and `0x004cf260`.
- `g_pIconsPane` is written by constructor and cleanup and cleared here at `0x004cfdc0`.

## Ownership Decision

Attach to [UID:00006B][IconsPane](by-class/IconsPane.md). The body is physically interleaved in the `TabPane` tail, but every class-specific signal is `IconsPane`: vtables, singleton clear, and adjustor-thunk refs.

## Score Rationale

Completion is assignment-floor because exact bounds, vtables, singleton clear, thunk refs, callees, flag behavior, and interleaved-owner rationale are documented. Confidence is strong for class ownership; final destructor naming/source spelling remains below final-audit confidence.

## Cross-References

- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
