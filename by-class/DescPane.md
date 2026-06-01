*** UID:00003Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DescPane

## Status

- Confidence: strong for class identity and field tail; medium for raw helper naming.
- Likely source file: [UID:0000IS][DescPane](by-file/DescPane.md)
- Address range: [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- Vtables: [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md), exact data [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md), bases `0x006189dc`, `0x00618a28`, and `0x00618a58`
- Current recovered file: `source-3/simroot_v2/class_DescPane.cpp`
- Imported source file: `DescPane.cpp`

## Class Purpose

`DescPane` is a singleton-backed description text pane. It stores a description provider pointer at `+0xf8` and a selected entry index at `+0xfc`. Refresh clears the pane text state, invalidates its bounds, and, when both fields are valid, calls the provider's virtual description method with the selected index and a local 2048-byte buffer.

The class is a reusable UI control, not a feature-dialog owner. The selected entry can represent item/object/list data supplied by another pane.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) | Constructs the `Pane` base with style `1`, installs three `DescPane` vtables, clears the source pointer, sets selected index to `-1`, and registers `g_pDescPane`. IDA currently reports this start as `Not a function`. |
| non-deleting destructor | [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) | Restores `DescPane` vtables, clears `g_pDescPane`, and jumps to shared pane-base cleanup. |
| singleton getter | [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) | Returns `g_pDescPane` from `0x0069adf8`. |
| raw source/index update helper | [UID:00012N][0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md) | Compares two arguments with `+0xf8` and `+0xfc`; when either changes, stores them and calls primary-vtable slot `+0x20` with pane bounds at `this+0x44`. Name and formal function status are unresolved. |
| `RefreshDescription` | [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneRefreshDescription](by-memory/0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md) | Sets text color to `0`, clears byte `+0x70`, invalidates bounds at `+0x44`, then calls provider vtable slot `+0x24` when source and selected index are valid. |
| destructor adjustor thunks | [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) | Adjust secondary-base `this` pointers by `-0xa0` and `-0xa4`, then forward to scalar deleting destructor. |
| scalar deleting destructor | [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) | Restores vtables, clears singleton, destroys the `Pane` base, and conditionally frees memory when `(flags & 1) != 0 && (flags & 4) == 0`. |

## Layout Notes

See [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md). The stable class-local tail is:

- `+0xf8`: description source/provider pointer.
- `+0xfc`: selected description index, initialized to `-1`.

The provider interface is not named yet. IDA decompilation of `RefreshDescription` calls `(*source->vtable[9])(source, selectedIndex, buffer)`, so the source likely exposes a `GetDescription(int index, char* outBuffer)`-style method.

## Evidence Notes

- Wave3 metadata reports `DescPane` as a 256-byte class imported from original `DescPane.cpp`.
- 2026-05-26 IDA vtable pass confirms three vtable bases at `0x006189dc`, `0x00618a28`, and `0x00618a58`; current `class_DescPane.meta_wave3` still reports `vtable_count: 0`.
- IDA xrefs to [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) are all inside this island: constructor store, non-deleting destructor clear, singleton getter read, and scalar deleting destructor clear.
- The active generated file omits the non-deleting destructor, singleton getter, and raw source/index update helper. Keep the memory doc beside this class before migrating.
- 2026-06-01 recheck: IDA reports no direct callers for the raw constructor or raw source/index setter starts, so current placement relies on vtable/global xrefs and the class island. `xrefs_to 0x0069adf8` remains limited to constructor/destructor/getter code inside this island, and xrefs to the three `DescPane` vtable bases confirm constructor stores plus destructor restores.

## Cross-References

- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md)
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md)
- [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)
- [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/80`.
  - Summary/evidence: singleton role, provider/index layout, constructor/destructor/getter/update/refresh/destructor glue, vtables, global xrefs, and generated omissions are documented; remaining uncertainty is raw helper naming and lack of direct caller xrefs.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms this as NexusTK-owned UI control code through the singleton global, DescPane vtable stores, and DescPane method island. Parent/code autogen remains blank because provider-interface names and raw helper names are not final.
- 2026-06-01 child evidence refresh:
  - Before: the class parent metadata was blank while child pages were still low-scored.
  - After: attached to [UID:0000IS][DescPane](by-file/DescPane.md); child constructor/setter/refresh pages now carry refreshed IDA MCP boundary, vtable, singleton, and provider-call evidence.
  - Summary/evidence: the raw constructor installs all three vtables and stores `g_pDescPane`; the raw setter updates `+0xf8/+0xfc` and invalidates; the modeled refresh reads the same fields and calls provider slot `+0x24`.
