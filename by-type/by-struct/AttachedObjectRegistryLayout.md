*** UID:0001TR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectRegistryLayout

## Status

- Confidence: medium-high for the listed offsets; class identity still provisional.
- Primary file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Primary memory: [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- Evidence basis: `simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp` plus IDA decompilation of `0x0053aec0`, rechecked on 2026-05-25 and 2026-05-26.
- Reconstructable: yes, as source-level registry layout information. Do not emit final C++ until the real owner class and constructor/setup code are identified.

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
