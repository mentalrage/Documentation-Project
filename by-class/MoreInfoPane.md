*** UID:00008Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MoreInfoPane

## Status

- Confidence: strong for two-method behavior, vtable placement, inline construction, and user-look-local ownership; medium-high for whether the observed singleton slot was source-retained.
- Likely source file: [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- Address range: [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- Current recovered file: `source-3/simroot_v2/class_MoreInfoPane.cpp`

## Class Purpose

`MoreInfoPane` is a minimal read-only child pane used by `UserLookPane` for the more-info view. It is constructed inline by `UserLookPane::UserLookPane` after a generic text/edit pane setup call, then receives its own vtable.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlwaysFalse` | `0x005a2340-0x005a2345` | Virtual gate that always returns false. |
| `AlwaysFalse2` | `0x005a2350-0x005a2355` | Second virtual gate that always returns false. |

## Evidence Notes

- IDA xrefs to the two functions are vtable slots at `0x0062edd8` and `0x0062edb8`.
- IDA decompilation of `UserLookPane::UserLookPane` allocates a `372`-byte pane, calls the common pane constructor, installs `MoreInfoPane` vtables, stores it at `UserLookPane + 0xf8`, and writes the same pointer to [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md).
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md) records the `MoreInfoPane` vtable family at `0x0062ed58`, `0x0062edd0`, and `0x0062ee00`, between the `UserLookPane` and `ProfilePane` table families.
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) independently records the same MoreInfoPane vtable bases, slot targets, and local child-pane placement.
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md) records `UserLookPane::ShowMoreInfoView` at `0x005a1cd0-0x005a1dee`, which activates mode `0` and lays out the MoreInfo child pane.

## Ownership And Parent Gate

This class is assigned to [UID:0000P0][UserLookPane](by-file/UserLookPane.md). The direct parent is refreshed to `88/85`, and this child is raised to `85/88`; both sides now clear the strict 85/85 gate.

The ownership is direct because `MoreInfoPane` is constructed inline by `UserLookPane::UserLookPane`, stored as a UserLookPane child, represented in the UserLook read-only vtable island, and activated by the UserLookPane more-info view switcher. The singleton slot remains a reconstruction caveat, but it does not indicate a broader owner because current docs show a constructor write and no recovered direct reader.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now documents the full two-method class behavior, constructor/store context, vtable bases, read-only-data range, singleton-slot caveat, view-switch use, and direct parent gate. Completion remains below 90 because this intentionally tiny class still lacks final source-level member names and the singleton slot's source-retention answer. |
| Confidence | 88 | Confidence is strong because independent class, executable, read-only-data, vtable-family, and singleton-slot pages all agree on local UserLookPane ownership. It remains below final because no final source declaration or member layout audit has been performed. |
| Parent | [UID:0000P0][UserLookPane](by-file/UserLookPane.md) | Child `85/88` and parent `88/85` clear the strict gate; by-structure ownership is direct as a local child pane of the user-look panel. |

## Cross-References

- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md)
- [UID:00026V][0x0062eccc-0x0062ef0c.UserLookReadOnlyData](by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md)
- [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md)

## Changes

- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:74`, `CONFIDENCE:86`, and no parent because the class page was too concise and the direct parent was below the stricter confidence gate.
  - After: `COMPLETION:85`, `CONFIDENCE:88`, and parent [UID:0000P0][UserLookPane](by-file/UserLookPane.md).
  - Why: [UID:0000P0][UserLookPane](by-file/UserLookPane.md) was refreshed to `88/85`; the executable aggregate, read-only vtable-data page, vtable-family page, singleton-slot page, and view-switch evidence all support direct user-look-local ownership.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the two always-false virtual methods at `0x005a2340` and `0x005a2350`. Left `AUTOGEN_PARENT_UID` blank at that time because this concise class page had not yet cleared the attachment gate even though [UID:0000P0][UserLookPane](by-file/UserLookPane.md) was the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `74/86`. Summary: the small user-look child pane has clear inline construction, vtable, storage, and two-method behavior evidence, but the page is inherently concise because the class only exposes two always-false virtual gates. Evidence: linked UserLookPane/profile range, `UserLookPane::UserLookPane` allocation/store evidence, vtable xrefs, and current Wave3 grade/method count.
