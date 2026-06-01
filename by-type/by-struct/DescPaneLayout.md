*** UID:0001U3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DescPane Layout

## Status

- Confidence: strong for class-local tail offsets and vtable/global anchors; medium for final source-facing provider interface names.
- Evidence basis: IDA disassembly/decompilation, [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) checks, and generated data only as a lead.

## Layout Summary

`DescPane` is a 256-byte `Pane`-derived object with three vtable views and a two-field class-local tail.

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `Pane` base / primary vtable | Primary pane object. |
| `+0x44` | inherited pane bounds/region | Passed to invalidation/update calls by the raw setter and refresh routine. |
| `+0x70` | inherited pane byte | Cleared by `RefreshDescription`; exact Pane-field name remains unresolved. |
| `+0xa0` | secondary vtable | Secondary inherited subobject using vtable base `0x00618a28` and destructor adjustor thunk `0x0049d81e`. |
| `+0xa4` | tertiary vtable | Tertiary inherited subobject using vtable base `0x00618a58` and destructor adjustor thunk `0x0049d829`. |
| `+0xf7` | padding/unknown byte | Wave3/Ghidra residual field before the local tail. |
| `+0xf8` | pointer/dword | Description source/provider pointer. |
| `+0xfc` | `int32` | Selected description index, initialized to `-1`. |

## Provider Interface Notes

`RefreshDescription` treats `+0xf8` as an object pointer and calls the function at provider vtable offset `+0x24` with `(selectedIndex, descBuffer)`. The local buffer is 2048 bytes. A provisional interface would look like:

```cpp
struct DescPaneDescriptionSource {
    virtual int Unknown0();
    virtual int Unknown1();
    virtual int Unknown2();
    virtual int Unknown3();
    virtual int Unknown4();
    virtual int Unknown5();
    virtual int Unknown6();
    virtual int Unknown7();
    virtual int Unknown8();
    virtual int GetDescription(int selectedIndex, char* outBuffer); // vtable slot +0x24
};
```

The earlier slots are not named from current evidence. Keep this as a forward-declared provider interface until consumers are recovered.

## Notes

- IDA currently has no local `DescPane` struct, while Wave3 metadata reports the Ghidra-derived size and fields. Use this layout as a documentation model, not an IDA-applied type.
- The `+0x44` and `+0x70` rows are inherited `Pane` state, included here because the `DescPane` methods use them directly.
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) records the primary table at `0x006189dc`; current `class_DescPane.meta_wave3` still reports `vtable_count: 0`.

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` confirms modeled functions at `0x0049d740`, `0x0049d770`, `0x0049d7c0`, `0x0049d81e`, `0x0049d829`, and `0x0049d840`; constructor `0x0049d6f0` and setter/update helper `0x0049d780` remain raw starts.
- IDA MCP decompilation of `0x0049d7c0` reads the provider pointer at `+0xf8`, selected index at `+0xfc`, clears inherited byte `+0x70`, invalidates with `this + 0x44`, and calls provider vtable slot `+0x24` with a 2048-byte local buffer.
- `xrefs_to 0x0069adf8` confirms `g_pDescPane` stores/clears/reads inside the DescPane island.
- `xrefs_to 0x006189dc` confirms the primary vtable is installed by the constructor/destructor paths.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)

## Changes

- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the field reads/writes, global singleton xrefs, vtable stores, and provider-call shape. The page remains below `95+` because exact provider-interface naming, raw helper naming, and full caller/use-site semantics are not final.
