*** UID:0000VJ | DO NOT MODIFY OR REMOVE!!! ***
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

# TransferServerDialogPaneThunks_599220_5993e0

## Status

- Confidence: very strong for exact boundaries, hashes, singleton behavior, ordinary destructor source shape, EH cleanup, adjustor/scalar ABI dispositions, and liveness routes.
- Current IDA state: all helper/thunk starts in this island are modeled as functions, but the final source shape should still treat most of this range as compiler-emitted destructor/thunk glue.
- Proposed owner file: [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- Exact memory range: [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)
- Rebuild handling: reviewed non-emitting compatibility index. Exact children own every byte and source/compiler disposition; this broad item preserves historical helper evidence without emitting duplicate C++.

## Exact Child Routes

- [UID:0004MW][0x00599220-0x00599248.TransferServerDialogPaneDestructor](by-memory/0x00599220-0x00599248.TransferServerDialogPaneDestructor.md): source-authored body clears `g_pTransferServerDialog`; compiler lowering restores views and tears down Pane.
- [UID:0004N0][0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton](by-memory/0x005993b0-0x005993ba.TransferServerDialogPaneConstructorUnwindClearSingleton.md): compiler EH cleanup with sole unwind route; blank.
- [UID:0004N1][0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks](by-memory/0x005993bb-0x005993d0.TransferServerDialogPaneDestructorAdjustorThunks.md): two compiler thunks adjusting `-0xa0/-0xa4`; blank.
- [UID:0004N2][0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor](by-memory/0x005993e0-0x0059943e.TransferServerDialogPaneScalarDeletingDestructor.md): compiler wrapper over ordinary destruction and conditional deallocation; blank.

The exact class declaration and ordinary destructor body live under owner [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md). A broad body, sample, covered-by marker, explicit vptr stores, helper declaration, adjustor, or scalar-wrapper source would duplicate accepted children or expose compiler ABI.

## Helper Summary

| Address range | Proposed role | Behavior |
| --- | --- | --- |
| `0x00599220-0x00599249` | non-deleting destructor helper | Restores all three `TransferServerDialogPane` vtables, clears [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md), and calls the base pane teardown at `0x00544580`. |
| `0x005993b0-0x005993bb` | singleton clear helper | Clears [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md) only; constructor unwind/cancel cleanup path. |
| `0x005993bb-0x005993c6` | adjustor thunk | Adjusts `this` by `-0xa0` bytes and forwards to `0x005993e0`. |
| `0x005993c6-0x005993d1` | adjustor thunk | Adjusts `this` by `-0xa4` bytes and forwards to `0x005993e0`. |
| `0x005993e0-0x0059943f` | scalar deleting destructor | Restores vtables, clears singleton, calls base pane teardown at `0x00544580`, and conditionally frees memory. |

## IDA MCP Evidence

Checked on 2026-05-24:

- `lookup_funcs` confirms every helper start listed above.
- Decompilation of `0x00599220` and `0x005993e0` both call `sub_544580` after clearing `dword_69B4B0`; this supports a `Pane` base teardown target rather than the stale `TextButtonExControlPane::~Pane` label.
- Decompilation of `0x005993b0` is only `dword_69B4B0 = 0`.
- Decompilation of `0x005993bb` and `0x005993c6` forwards to `0x005993e0` after subtracting `40` or `41` dwords from `this`.
- `xrefs_to 0x005993bb` and `xrefs_to 0x005993c6` show vtable/data refs at `0x0062e4cc` and `0x0062e4fc`; `xrefs_to 0x005993e0` also reports vtable/data ref `0x0062e480`.
- `xrefs_to 0x00599220` reports no direct xrefs, consistent with a non-virtual cleanup helper or exception/unwind-only path.

Rechecked on 2026-05-31:

- IDA reports `0x00599220` as `sub_599220` with exclusive end `0x00599249`; it restores three TransferServerDialogPane vtables, clears `dword_69B4B0`, and calls base teardown `0x00544580`.
- IDA reports `0x005993b0` as `sub_5993B0` with exclusive end `0x005993bb`; it only clears `dword_69B4B0` and now has a code reference from `0x00609c11`.
- IDA reports adjustor thunks `0x005993bb-0x005993c6` and `0x005993c6-0x005993d1`, each forwarding to `0x005993e0` after subtracting `40` or `41` dwords from `this`.
- IDA reports `0x005993e0` as `sub_5993E0` with exclusive end `0x0059943f`; it restores the same vtables, clears `dword_69B4B0`, tears down through `0x00544580`, and conditionally frees through `0x004f4ac0`.

Rechecked on 2026-06-04:

- Live IDA reports exact function ranges `0x00599220-0x00599249`, `0x005993b0-0x005993bb`, `0x005993bb-0x005993c6`, `0x005993c6-0x005993d1`, and `0x005993e0-0x0059943f`.
- `0x00599220` writes `??_7TransferServerDialogPane@@6B@`, `??_7TransferServerDialogPane@@6B@_0`, and `??_7TransferServerDialogPane@@6B@_1`, clears `dword_69B4B0`, then calls `sub_544580`.
- `0x005993b0` has the single code xref from constructor unwind code at `0x00609c11` and only clears `dword_69B4B0`.
- `0x005993bb` and `0x005993c6` are 0x0b-byte adjustor thunks with data refs from the secondary and tertiary TransferServerDialogPane vtables at `0x0062e4cc` and `0x0062e4fc`; both forward to `0x005993e0`.
- `0x005993e0` restores the same three vtables, clears `dword_69B4B0`, calls `sub_544580`, conditionally calls `sub_4F4AC0` when scalar deletion is requested, and has the primary vtable data ref at `0x0062e480`.
- `sub_544580` writes the three `Pane` vtables at `0x006219e8`, `0x00621a34`, and `0x00621a64`, so the helper island is correctly modeled as TransferServerDialogPane teardown flowing into Pane teardown rather than a separate text-button owner.

Rechecked on 2026-06-16 by A002 with live IDA MCP session `c001_midiplayer_rdata_20260615`:

- `lookup_funcs` reconfirmed exact function starts and sizes: `0x00599220` size `0x29`, `0x005993b0` size `0x0b`, `0x005993bb` size `0x0b`, `0x005993c6` size `0x0b`, and `0x005993e0` size `0x5f`. Boundary probes at `0x00599249`, `0x005993a6`, `0x005993d1`, and `0x0059943f` are not function starts.
- `get_bytes` reconfirmed padding around this island: seven `0xcc` bytes at `0x00599249-0x00599250`, ten `0xcc` bytes at `0x005993a6-0x005993b0`, fifteen `0xcc` bytes at `0x005993d1-0x005993e0`, and one `0xcc` byte at `0x0059943f`.
- `analyze_function` reconfirmed the source behavior: `0x00599220` writes all three `TransferServerDialogPane` vtables, clears `0x0069b4b0`, then calls `0x00544580`; `0x005993b0` only clears `0x0069b4b0`; `0x005993bb` adjusts `this` by `-0xa0`; `0x005993c6` adjusts `this` by `-0xa4`; and `0x005993e0` writes the same vtables, clears the singleton, calls `0x00544580`, and conditionally frees through `0x004f4ac0`.
- `xref_query` reports zero direct xrefs to `0x00599220`, one constructor-unwind code xref to the singleton clear helper `0x005993b0` from `0x00609c11`, vtable data refs to the adjustor thunks at `0x0062e4cc`/`0x0062e4fc`, two thunk code refs plus one primary vtable data ref to `0x005993e0`, and 20 direct refs to the singleton slot `0x0069b4b0`.
- `find_bytes` for VA/RVA pointer forms found no pointer-byte hits for `0x00599220` or `0x005993b0`, and only the expected vtable-table hits for `0x005993bb`, `0x005993c6`, and `0x005993e0`. This keeps the non-deleting helper and singleton-clear helper as real modeled code, but not safe standalone source methods.
- Unique entry signatures were recorded for the helper island. The short helper/thunk signatures necessarily include adjacent bytes because of their small size, while the scalar destructor entry signature is `55 8B EC 56 8B F1 C7 06 80 E4 62 00`.

## Ownership Decision

Keep this whole helper island with `TransferServerDialogPane.cpp`. It is compiler/helper glue for the three-vtable pane object plus the transfer overlay singleton, not evidence for a separate source file or for ownership by `TextButtonExControlPane`.

The evidence supports representing this island through the class declaration, destructor, timer-handler inheritance layout, and compiler-emitted adjustor/scalar-deleting thunks in final source. It does not yet support hand-writing standalone source methods for `0x00599220` or `0x005993b0`: both remain useful documentation anchors, but `0x00599220` has no direct refs or pointer-byte hits, and `0x005993b0` is reached only by the constructor unwind cleanup path.

## Cross-References

- [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md)
- [UID:0000F7][TransferServerDialogPane](by-class/TransferServerDialogPane.md)
- [UID:0000SL][g_pTransferServerDialog](by-global/g_pTransferServerDialog.md)
- [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the destructor helper, singleton clear helper, adjustor thunks, scalar deleting destructor, vtable refs, and teardown/free callees. Final source modeling remains incomplete because compiler-emitted destructor glue and base teardown ownership are not fully audited.
- 2026-06-04: Raised item coverage and parent-attached it to [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md).
  - What existed before: `COMPLETION:70`, `CONFIDENCE:85`, and blank owner/emitter metadata. The page had correct high-level behavior but stale source-state framing and inclusive/unclear helper ends.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, and owner/emitter routing to [UID:0000OW][TransferServerDialogPane](by-file/TransferServerDialogPane.md); reconstruction C++ remains blank because the destructor/thunk source shape is still not final-source quality.
  - Summary/evidence: live IDA MCP on 2026-06-04 confirmed exact exclusive ranges, three TransferServerDialogPane vtable refs, singleton clear refs, constructor unwind xref to the clear helper, adjustor thunk forwarding, Pane teardown through `0x00544580`, and conditional free through `0x004f4ac0`.
- 2026-06-16 A002 target support refresh:
  - Before: `84/90`.
  - After: `86/91`.
  - Summary/evidence: live IDA MCP reconfirmed exact function starts/sizes, padding bytes, vtable refs, singleton refs, constructor-unwind-only clear-helper reachability, no direct refs or VA/RVA pointer-byte hits for the non-deleting helper, and the expected vtable-table hits for adjustor/scalar-deleting destructor entries. The remaining blocker is the final source representation of compiler-emitted destructor/thunk glue.
