*** UID:0000FU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VersatileAlertPane

## Status

- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Address ranges: [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md), raw cleanup [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md), and [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md)
- Vtables: [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md) at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`.
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md), with callback pointer at `+0x270`.
- Current recovered file: `source-3/simroot_v2/class_VersatileAlertPane.cpp`
- Confidence: strong for behavior; medium for generated type names.
- Autogen status: reconstructable class shell parented to [UID:0000HE][AlertPanes](by-file/AlertPanes.md); final C++ remains blank until the callback interface and alert base type names are source-quality.

## Class Purpose

`VersatileAlertPane` is a thin `AlertPane` subclass that reports accept/cancel results through a stored callback object. It is a generic prompt wrapper rather than a feature-specific dialog.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `VersatileAlertPane` | `0x004a0690-0x004a06d7` | Calls `AlertPane::AlertPane`, stores the callback/control pointer, and installs three `VersatileAlertPane` vtables. |
| cleanup-shaped body | [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md) | Reinstalls the three class vtables, releases the stored callback when present, and jumps to alert base teardown. IDA does not currently model this as a function and reports no callers. |
| `OnAccept` | `0x004a0720-0x004a0732` | Calls callback vtable slot `3` with result `1` when present. |
| `OnCancel` | `0x004a0740-0x004a0752` | Calls callback vtable slot `3` with result `0` when present. |
| `AdjustorThunk` | `0x004a0cb0-0x004a0ccb` | Secondary/tertiary vtable adjustor thunks into the deleting destructor. |
| `ScalarDeletingDestructor` | `0x004a0cd0-0x004a0d37` | Releases the stored callback object through vtable slot `0`, tears down the alert base, and optionally deletes storage. |

## Evidence Notes

- IDA decompilation of `0x004a0690` directly calls `0x0049feb0`, stores the callback/control value at object offset `0x270`, and patches all three vtables.
- 2026-05-26 IDA MCP vtable pass confirms `VersatileAlertPane` primary/secondary/tertiary vtables at `0x00618ba4`, `0x00618c0c`, and `0x00618c3c`, installed by constructor stores at `0x004a06b6`, `0x004a06bc`, and `0x004a06c6`.
- 2026-05-26 IDA layout pass confirms constructor store and cleanup/destructor reads of the callback pointer at `+0x270`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- The primary table overrides `AlertPane` callback extension slots `+0x5c` and `+0x60` with `OnAccept` and `OnCancel`; most drawing and dialog slots remain inherited.
- IDA raw disassembly shows `0x004a06e0-0x004a0714` as unreferenced cleanup-shaped code, not currently an IDA function. It has no `xrefs_to 0x004a06e0`, but vtable-store xrefs land at `0x004a06e9`, `0x004a06ef`, and `0x004a06f9`; prewave also has a matching 53-byte function record.
- IDA xrefs to the constructor include calls from `0x005301de` and `0x0058b5c5`.
- `0x004a0760` is `ModelessDialogPane` construction and should not be treated as `VersatileAlertPane` despite address locality.

## Data Caveats

- Current generated source contains a stray `BackGroundPane` deleting-destructor typedef and labels the base teardown as `TransferReplyAlert::~TransferReplyAlert`. Treat both as owner/type pollution until Wave3 data is cleaned.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md)
- [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md)
- [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the constructor/callback/cleanup/destructor/thunk behavior, vtable and layout evidence, constructor xrefs, raw cleanup caveat, and generated type/owner pollution notes.
