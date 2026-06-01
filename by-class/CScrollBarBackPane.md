*** UID:00003D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CScrollBarBackPane

## Status

- Confidence: strong for class behavior and boundaries; medium-high for final source-file placement.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address ranges: `0x0053fea0-0x0053ff8d` and `0x00542680-0x005426d5`
- Current recovered file: `source-3/simroot_v2/class_CScrollBarBackPane.cpp`

## Class Purpose

`CScrollBarBackPane` is a small pane that draws a fixed scrollbar background/backplate pattern using line drawing. It initializes three vtable pointers and has standard scalar deleting teardown.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x0053fea0-0x0053fed2` | `CScrollBarBackPane` | Constructs the `Pane` base and installs primary/secondary vtables. |
| `0x0053fee0-0x0053feff` | cleanup helper | Restores the three `CScrollBarBackPane` vtables and tail-jumps to the base teardown helper. |
| `0x0053ff00-0x0053ff8d` | `DrawScrollBarBackPattern` | Draws fixed horizontal and vertical line segments through `g_pfnDrawLineDelta`. |
| `0x00542680-0x005426d5` | `ScalarDeletingDestructor` | Resets vtables, destroys base subobject, optionally deletes memory. |
| [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) | disabled thunks | Excluded adjustor thunk material around the deleting destructor. |

## Evidence Notes

- IDA MCP and Wave3 metadata identify `0x0054259f` and `0x005425aa` as this-adjustor thunks into the scalar deleting destructor.
- `DrawScrollBarBackPattern` uses fixed coordinates from `0` through `100`, consistent with a scrollbar backplate, not a feature pane.
- Current generated source types destructor support through unrelated classes (`BowGaugeObjectPane` and `TextButtonExControlPane`), which is likely owner-name pollution.
- 2026-06-01 IDA MCP confirms the constructor bytes at `0x0053fea0-0x0053fed2`; IDA does not define a function object there, but the disassembly shows the `Pane`-base constructor call `0x00544460`, writes vtables at `+0x0`, `+0xa0`, and `+0xa4`, returns `this`, and then aligns to the helper at `0x0053fee0`.
- 2026-06-01 IDA MCP confirms cleanup helper `sub_53FEE0` at `0x0053fee0-0x0053feff`; it restores the same three vtables and tail-jumps to `0x00544580`.
- 2026-06-01 IDA MCP confirms draw method `sub_53FF00` at `0x0053ff00-0x0053ff8d`; it alternates position helper `0x004b9600` with indirect line-delta calls through `dword_69B3E4`.
- 2026-06-01 IDA MCP xrefs: draw method referenced from `0x00621060`; scalar deleting destructor referenced from `0x0062101c` and adjustor jumps `0x005425a5`/`0x005425b0`; adjustor thunks referenced from `0x00621068` and `0x00621098`.

## Reconstruction Notes

- Reconstructable is `TRUE` because the class methods, vtable writes, destructor/thunk relationship, and ScrollBar parent are now backed by IDA evidence.
- The C++ block remains blank because `dword_69B3E4`, helper names `0x004b9600`/`0x00544460`/`0x00544580`, and exact original placement of this small backplate pane are not final-source quality.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md)
- [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## Changes

- 2026-05-28: Changed `DrawScrollBarBackPattern` from `0x0053ff00-0x0053ff8c` to `0x0053ff00-0x0053ff8d`.
  - Before: the method map omitted the function's final `ret` byte.
  - After: the method map matches IDA's full function boundary.
  - Evidence: IDA MCP reports `sub_53FF00` as `0x0053ff00-0x0053ff8d`.
- 2026-05-28: Changed `ScalarDeletingDestructor` from `0x00542680-0x005426d4` to `0x00542680-0x005426d5`.
  - Before: the method map omitted the final byte of the destructor wrapper and left the following bytes as UNKNOWN.
  - After: the method map matches IDA's full function boundary, with following padding and destructor-island rows split separately.
  - Evidence: IDA MCP reports `sub_542680` as `0x00542680-0x005426d5`.
- What existed before: the page had class behavior, method boundaries, and prior range corrections, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor, draw pattern, destructor, and thunk island are documented; final source-file placement and exact class declaration remain incomplete.
- 2026-06-01: Changed completion/confidence from `72/80` to `78/84`, marked reconstructable, and attached parent [UID:0000NF][ScrollBar](by-file/ScrollBar.md).
  - Before: the method map omitted the local cleanup helper and parent autogen metadata was blank.
  - After: current IDA MCP evidence records the constructor bytes, cleanup helper, draw method, destructor xrefs, and vtable refs. C++ remains blank pending final helper/global names.
