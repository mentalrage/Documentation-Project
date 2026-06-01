*** UID:0000VJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TransferServerDialogPaneThunks_599220_5993e0

## Status

- Confidence: strong for helper behavior, medium for final modeling policy.
- Current Wave3 state: `0x00599220`, `0x005993b0`, and helper/thunk starts are not all modeled as active methods; generated destructor still names a polluted base owner.
- Proposed owner file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- Exact memory range: [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- Rebuild handling: mostly `source-declared/generated-binary` destructor/thunk output plus singleton cleanup semantics. Marked reconstructable because the class declaration/destructor behavior and singleton cleanup must be reproduced, but parent attachment and C++ are blank until the full class and base teardown chain are audited.

## Helper Summary

| Address range | Proposed role | Behavior |
| --- | --- | --- |
| `0x00599220-0x00599248` | non-deleting destructor helper | Restores all three `TransferServerDialogPane` vtables, clears [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), and calls the base pane teardown at `0x00544580`. |
| `0x005993b0-0x005993ba` | singleton clear helper | Clears [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) only; likely constructor/unwind or cleanup helper. |
| `0x005993bb-0x005993c5` | adjustor thunk | Adjusts `this` by `-0xa0` bytes and forwards to `0x005993e0`. |
| `0x005993c6-0x005993d0` | adjustor thunk | Adjusts `this` by `-0xa4` bytes and forwards to `0x005993e0`. |
| `0x005993e0-0x0059943f` | scalar deleting destructor | Restores vtables, clears singleton, calls base pane teardown at `0x00544580`, and conditionally frees memory. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms every helper start listed above.
- Decompilation of `0x00599220` and `0x005993e0` both call `sub_544580` after clearing `dword_69B4B0`; this supports a `Pane` base teardown target rather than the generated `TextButtonExControlPane::~Pane` label.
- Decompilation of `0x005993b0` is only `dword_69B4B0 = 0`.
- Decompilation of `0x005993bb` and `0x005993c6` forwards to `0x005993e0` after subtracting `40` or `41` dwords from `this`.
- `xrefs_to 0x005993bb` and `xrefs_to 0x005993c6` show vtable/data refs at `0x0062e4cc` and `0x0062e4fc`; `xrefs_to 0x005993e0` also reports vtable/data ref `0x0062e480`.
- `xrefs_to 0x00599220` reports no direct xrefs, consistent with a non-virtual cleanup helper or exception/unwind-only path.

Rechecked on 2026-05-31:

- IDA reports `0x00599220` as `sub_599220` with exclusive end `0x00599249`; it restores three TransferServerDialogPane vtables, clears `dword_69B4B0`, and calls base teardown `0x00544580`.
- IDA reports `0x005993b0` as `sub_5993B0` with exclusive end `0x005993bb`; it only clears `dword_69B4B0` and now has a code reference from `0x00609c11`.
- IDA reports adjustor thunks `0x005993bb-0x005993c5` and `0x005993c6-0x005993d0`, each forwarding to `0x005993e0` after subtracting `40` or `41` dwords from `this`.
- IDA reports `0x005993e0` as `sub_5993E0` with exclusive end `0x0059943f`; it restores the same vtables, clears `dword_69B4B0`, tears down through `0x00544580`, and conditionally frees through `0x004f4ac0`.

## Ownership Decision

Keep this whole helper island with `TransferServerDialogPane.cpp`. It is compiler/helper glue for the three-vtable pane object plus the transfer overlay singleton, not evidence for a separate source file or for ownership by `TextButtonExControlPane`.

## Cross-References

- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the destructor helper, singleton clear helper, adjustor thunks, scalar deleting destructor, vtable refs, and teardown/free callees. The score remains below 95 because final source modeling of compiler-emitted destructor glue and base teardown ownership is not fully audited.
