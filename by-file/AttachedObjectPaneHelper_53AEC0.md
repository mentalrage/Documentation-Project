*** UID:0000HK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AttachedObjectPaneHelper_53AEC0

## Status

- Confidence: strong that `0x0053aec0` is real detach-registry code; low that this was an original standalone source file.
- Proposed owner: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), likely as a private helper/registry method in `map/AttachedObjectPane.cpp`.
- Current generated source: `source-3/simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp`
- Main address doc: [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)

## File Role

This page exists to quarantine a generated one-method file split. The recovered method removes an `AttachedObjectPane`-derived overlay from an owner/registry object when the overlay is destroyed.

The method is called only from `AttachedObjectPane::~AttachedObjectPane` at `0x005382b0`. The destructor reads its registry pointer from `AttachedObjectPane + 0x128` and calls `sub_53AEC0(registry, this)`, so the generated class name should not drive final source layout.

## Ownership Decision

Do not create a final `AttachedObjectPaneHelper_53AEC0.cpp` source file unless later evidence recovers a broader named manager class around the same object layout.

For now, fold the function into [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) as a private registry/list cleanup helper:

| Entity | Evidence | Proposed placement |
| --- | --- | --- |
| `AttachedObjectPaneHelper_53AEC0::DetachAttachedObject` | `0x0053aec0-0x0053b011`; only caller is `AttachedObjectPane::~AttachedObjectPane` | Private helper in `map/AttachedObjectPane.cpp`. |
| registry layout | list pointers at `+0x170` and `+0x174`; singleton slots at `+0x1d8-0x1e4` | [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md). |
| `g_attachmentModeFlag` generated alias | IDA name is `byte_66DA97`; broad UI/render mode selector with 366 xrefs | [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), not an attachment-specific global. |

## Evidence Notes

- 2026-05-25 recheck using current `simroot_v2` plus IDA MCP: the generated file still emits standalone `AttachedObjectPaneHelper_53AEC0::DetachAttachedObject` and the misleading `g_attachmentModeFlag` alias.
- 2026-05-26 recheck using current `simroot_v2` plus IDA MCP: the generated file remains a one-method split, and IDA caller/xref evidence is unchanged.
- IDA MCP `lookup_funcs` confirms `sub_53AEC0` at `0x0053aec0` with size `0x152`.
- IDA MCP `callers` and `xrefs_to` report a single code caller at `0x005382b0` inside `sub_538100`, the `AttachedObjectPane` non-deleting destructor.
- IDA decompilation of `0x00538100` shows the call shape `sub_53AEC0(*(this + 0x128), this)`.
- IDA decompilation of `0x0053aec0` confirms registry offsets `+0x170`, `+0x174`, `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- The helper reads the attached object's type byte at `attachedObject + 0xf8`.
- The helper removes type `2` and type `4` objects from registry lists and clears type `6`, `7`, `8`, and `9` singleton slots. Type `8` clears only when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` is `1`.
- IDA MCP `py_eval` on 2026-05-26 reconfirmed 366 xrefs to `byte_66DA97`, so the generated alias remains a broad UI/render mode byte rather than attachment-specific state.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- What existed before: the page quarantined the generated helper split but had unevaluated scores.
- What it was changed to: scores were set to `74/88`.
- Summary and evidence: the code behavior and non-standalone ownership decision are strongly supported by IDA caller/xref evidence; completion is lower because this should likely be folded into `AttachedObjectPane.cpp` after migration.
