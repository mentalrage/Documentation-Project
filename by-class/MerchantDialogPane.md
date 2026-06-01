*** UID:000083 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MerchantDialogPane

## Status

- Confidence: strong for class role and shared virtual ownership; medium for exact original file split.
- Likely source file: [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- Address range: [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- Exact shared virtual: [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- Current recovered file: `source-3/simroot_v2/class_MerchantDialogPane.cpp` is incomplete generated-output context; current class ownership is IDA-backed.

## Class Purpose

`MerchantDialogPane` is the shared base for merchant/NPC menu dialogs. It derives from [UID:00003T][DialogPane](by-class/DialogPane.md), initializes the dialog with an empty title and modal flags, stores a one-byte merchant/menu type at `+0x26c`, and supplies a virtual helper used by text, item, spell, and argumented menu dialogs.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00517d30-0x00517d71` | Builds the `DialogPane` base, stores the merchant type byte, and installs the `MerchantDialogPane` vtables. |
| shared action-string virtual | [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) | Accepts slash-prefixed action strings, parses `0...` encoded action payloads, and emits a compact 10-byte outbound packet buffer. |

## Evidence Notes

- IDA `lookup_funcs` reports `0x00517d30` as not currently modeled as a function, but disassembly confirms a complete constructor body.
- IDA models `0x00517d80` as `sub_517D80`, size `0x13f`; xrefs are vtable data entries, not normal call sites.
- The `0x00517d80` vtable references sit in `MerchantDialogPane`, `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog` vtables.
- `0x00517ec0` begins the `TextMenuDialog` island and should not be merged into this base class.
- 2026-06-01 IDA MCP recheck reconfirms that `0x00517d30` is still unmodeled but constructor-shaped, stores the three `MerchantDialogPane` vtable bases, and has no direct xrefs. `0x00517d80` remains a modeled vtable-only virtual with data refs from the merchant/text/item/spell/argumented menu dialog vtables.
- Current generated output still shows only the constructor in `class_MerchantDialogPane.cpp`; keep the shared virtual in the class plan even though current generation omits it.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md) because the file parent now has enough IDA-backed confidence and the class role is shared across the merchant menu-dialog family.
- C++ remains blank because the constructor start is not an IDA function object and final source placement is not yet `95+` confidence.

## Cross-References

- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0000ES][TextMenuDialog](by-class/TextMenuDialog.md)
- [UID:0000ER][TextInputMenuDialog](by-class/TextInputMenuDialog.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:0000D3][ServerSpellMenuDialog](by-class/ServerSpellMenuDialog.md)
- [UID:00002R][ClientSpellMenuDialog](by-class/ClientSpellMenuDialog.md)
- [UID:00000H][ArgumentedMenuMenuDialog](by-class/ArgumentedMenuMenuDialog.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/78`. Summary: the shared merchant/NPC menu-dialog base has responsibility, source-owner candidates, constructor behavior, shared virtual behavior, vtable references, and derived-dialog relationships documented, but exact file split and constructor function modeling remain medium confidence. Evidence: linked base/action-string memory pages, IDA-modeled `0x00517d80` shared virtual, vtable references across merchant dialog variants, and `0x00517ec0` island boundary note.
- 2026-06-01 IDA MCP rescore: `76/78` -> `82/82`; marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md). Evidence: constructor bytes/vtable stores, shared virtual vtable xrefs, and text-menu boundary rechecked in IDA.
