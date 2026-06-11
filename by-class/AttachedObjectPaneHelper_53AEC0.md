*** UID:00000N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectPaneHelper_53AEC0

## Status

- Confidence: strong for method behavior; provisional/rejected as a final class name.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Exact helper range: [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- Disposition: not reconstructable as a standalone class; the reconstructable helper function belongs under the attached-object source root.

## Class Purpose

`AttachedObjectPaneHelper_53AEC0` is a rejected pseudo-class name around one detach bookkeeping method. The real object appears to be the attachment registry or owner pointer stored in [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) at offset `+0x128`.

The method removes a destroyed attached overlay from registry storage. It uses the destroyed object's type byte at `+0xf8` to decide whether to remove it from a pointer list or clear a singleton slot.

## Ownership Decision

- Treat this as a generated/provisional pseudo-class name, not a likely final C++ class name.
- The real owner is the attachment registry/manager pointer passed from [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) offset `+0x128`.
- Keep the page as an index for the rejected class identity because the registry layout is important, but place final source code with [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) or a recovered registry helper.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DetachAttachedObject` | `0x0053aec0-0x0053b011` | Removes type `2` and `4` overlays from registry pointer lists; clears type `6`, `7`, `8`, and `9` singleton slots. Type `8` is only cleared when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`. |

## Layout Notes

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x170` | `type2Attachments` | Pointer-list owner for attachment type `2`. |
| `+0x174` | `type4Attachments` | Pointer-list owner for attachment type `4`. |
| `+0x1d8` | `type6Attachment` | Singleton attachment slot. |
| `+0x1dc` | `type7Attachment` | Singleton attachment slot. |
| `+0x1e0` | `type8Attachment` | Singleton attachment slot, cleared only in current/EPF layout mode. |
| `+0x1e4` | `type9Attachment` | Singleton attachment slot. |

## Evidence Notes

- 2026-05-25 IDA MCP recheck confirms `0x0053aec0` is still only referenced from `0x005382b0` inside `AttachedObjectPane::~AttachedObjectPane`.
- 2026-05-26 IDA MCP recheck again reports `sub_53AEC0` size `0x152`, a single caller/xref at `0x005382b0`, and the destructor call shape `sub_53AEC0(*(this + 0x128), this)`.
- `AttachedObjectPane::~AttachedObjectPane` at `0x00538100-0x005382f8` is the only IDA-confirmed caller.
- The call passes the `AttachedObjectPane` itself as the detached object and the field at `AttachedObjectPane + 0x128` as this helper's `this` pointer.
- The historical generated global name `g_attachmentModeFlag` is misleading. The canonical global is [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md); preserve `byte_66DA97` only as the IDA lookup alias.
- 2026-05-26 decompilation reconfirmed the current/EPF branch clears type `8` at registry `+0x1e0`; the legacy branch does not clear that slot.

## Non-Standalone State

- `RECONSTRUCTABLE:FALSE` is intentional for this class page. The exact helper body is reconstructable through [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md), not as a source-level class declaration named `AttachedObjectPaneHelper_53AEC0`.
- Do not attach this page to the file root or emit class C++ unless later evidence proves a real allocated registry class with constructor/setup ownership.
- Keep the final owner open between a private helper on [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) and a future recovered registry helper type; current docs only prove the destructor-owned cleanup call.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0000HK][AttachedObjectPaneHelper_53AEC0](by-file/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-06-07 A008 alias cleanup:
  - Before: method and evidence notes still described the type `8` branch through the bare `byte_66DA97` / generated `g_attachmentModeFlag` names.
  - Changed to: canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) wording with `byte_66DA97` retained as the historical IDA alias.
  - Evidence: this does not change class disposition or behavior; it only aligns the helper with the reviewed global identity.
- 2026-06-06 non-standalone cleanup:
  - Before: the page already rejected the helper name but still used recovered-source/Wave-derived status wording and the manual coverage row still treated it as reconstructable.
  - Changed to: `82/88`, explicit exact-helper range reference, non-standalone state, and historical-generated-name wording while preserving `RECONSTRUCTABLE:FALSE`.
  - Evidence: [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md) records the exact helper, [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) records the destructor caller and registry field, and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) is the current source root.
- 2026-06-05: Changed autogen reconstructability from blank to `FALSE`.
  - Before: the page already rejected `AttachedObjectPaneHelper_53AEC0` as a final class name, but blank metadata left it unclassified in `-ag-class-coverage.md`.
  - After: the page is explicitly non-reconstructable as a standalone class; the real helper behavior stays documented under [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md), [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), and the exact memory range.
  - Evidence: live IDA MCP on 2026-06-05 confirms `sub_53AEC0` at `0x0053aec0` (`0x152` bytes) and a single direct caller at `0x005382b0` inside `sub_538100`, matching the documented destructor-owned registry helper.
- What existed before: the page documented the detach helper and provisional-name warning but still had unevaluated scores.
- What it was changed to: scores were set to `76/88`, and an ownership-decision section was added to make the pseudo-class status explicit.
- Summary and evidence: IDA confirms a single caller from `AttachedObjectPane::~AttachedObjectPane`, the registry pointer call shape, and clear slot/list behavior; confidence is strong for behavior but the final source owner is intentionally not treated as a standalone class.
