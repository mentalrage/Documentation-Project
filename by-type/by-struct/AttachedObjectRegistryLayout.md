*** UID:0001TR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectRegistryLayout

## Status

- Entity kind: class layout support struct for the attached-object detach registry.
- Confidence: strong for the listed offsets, caller shape, detach-helper data flow, and `AttachedObjectPane.cpp` source-family ownership; medium for the final registry owner class name and constructor/setup fields.
- Primary file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Primary memory: [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- Evidence basis: `simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp` plus IDA decompilation of `0x0053aec0`, rechecked on 2026-05-25 and 2026-05-26.
- Reconstructable: yes, as source-level registry layout information. Do not emit final C++ until the real owner class and constructor/setup code are identified.
- Parent assignment: attached to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), matching the documented decision to fold the generated one-method registry helper into the attached-object overlay source family unless later setup evidence identifies a broader manager class.

## Layout

This layout describes the registry/list-owner object passed as `this` to the detach helper at `0x0053aec0`. The object pointer is stored in [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) at offset `+0x128`.

| Offset | Field | Type | Evidence |
| --- | --- | --- | --- |
| `+0x170` | `type2Attachments` | pointer-list pointer | `0x0053aec0` gets list data through vtable slot `+0x0c`, scans for the detached object, then calls remove slot `+0x1c`. |
| `+0x174` | `type4Attachments` | pointer-list pointer | Same list pattern as `+0x170`, selected by attached object type `4`. |
| `+0x1d8` | `type6Attachment` | pointer | Cleared for attached object type `6`. |
| `+0x1dc` | `type7Attachment` | pointer | Cleared for attached object type `7`. |
| `+0x1e0` | `type8Attachment` | pointer | Cleared for attached object type `8` only when `byte_66DA97 == 1`. |
| `+0x1e4` | `type9Attachment` | pointer | Cleared for attached object type `9`. |

## Related Object Fields

The detached object uses byte offset `+0xf8` as its attachment-type discriminator. Current observed values are `2`, `4`, `6`, `7`, `8`, and `9`.

## Live IDA Evidence

- 2026-06-03 restarted IDA MCP reports the detach helper as `void __thiscall(int this, int)`: the registry/list-owner object is `this`, and the detached attached-object pointer is the single explicit argument.
- IDA caller analysis confirms one call site, `0x005382b0` inside [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)'s destructor. Decompilation shows the destructor call shape `sub_53AEC0(*(this + 0x128), this)`, proving the registry pointer is stored at `AttachedObjectPane + 0x128`.
- IDA callee analysis reports no outgoing helper calls from `0x0053aec0`; all list operations are vtable dispatches through the list objects stored in this registry.
- Decompilation gates behavior on a non-null detached object and the detached object's signed byte at `+0xf8`, accepting values in the `2..9` range.
- For attachment type `2`, the helper reads the list pointer at registry offset `+0x170`, retrieves list data through vtable slot `+0x0c`, scans the list count at list offset `+0x0c`, and removes the matching object through vtable slot `+0x1c` with remove flag `1`.
- Attachment type `4` uses the same list pattern through registry offset `+0x174`.
- Attachment types `6`, `7`, and `9` clear registry offsets `+0x1d8`, `+0x1dc`, and `+0x1e4`.
- Attachment type `8` clears registry offset `+0x1e0` only when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` equals `1`; the legacy/non-EPF branch does not clear that slot.

## Naming Notes

- `AttachedObjectPaneHelper_53AEC0` is a generated pseudo-class, not a stable original name.
- A future pass should search for constructor/setup code that initializes the lists at `+0x170` and `+0x174`; that code will likely identify the real owner class.
- The `byte_66DA97` branch is layout/rendering mode behavior, not an attachment subsystem flag.
- Current `simroot_v2` still emits the byte as `g_attachmentModeFlag`; normalize that alias to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) in project docs.
- 2026-05-26 IDA MCP recheck reconfirmed the listed offsets and showed type `8` is cleared only in the `byte_66DA97 == 1` branch.
- 2026-05-31 IDA MCP recheck of `0x0053aec0` confirms the type discriminator read at detached-object offset `+0xf8`, list-object accesses through this-object offsets `+0x170` and `+0x174`, and pointer clears at `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- The same decompilation confirms type `8` clearing at `+0x1e0` only occurs in the `byte_66DA97 == 1` branch, while types `6`, `7`, and `9` clear their dedicated pointers in the broader fallback branch.

## Open Questions

- The registry/list-owner class identity is still provisional until initialization code for `+0x170` and `+0x174` is found.
- Final field names should wait for attachment-type semantics and owner class naming, not only this detach helper.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000HK][AttachedObjectPaneHelper_53AEC0](by-file/AttachedObjectPaneHelper_53AEC0.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-03 restarted IDA MCP evidence and parent assignment:
  - What existed before: scores were `68/82`, and autogen parent metadata was blank.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000HJ`.
  - Summary/evidence: live IDA MCP confirms the `void __thiscall(int this, int)` detach-helper shape, single destructor caller, registry pointer source at `AttachedObjectPane + 0x128`, detached-object type byte at `+0xf8`, list offsets `+0x170/+0x174`, singleton offsets `+0x1d8/+0x1dc/+0x1e0/+0x1e4`, no direct helper callees, and the `g_useEpfAssets`-gated type `8` clear. C++ remains blank because final registry owner/type names and constructor/setup evidence are not at the 95+ gate.
