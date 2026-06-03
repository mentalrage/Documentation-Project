*** UID:000075 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LightingObjectPane

## Status

- Confidence: strong for lifecycle and intensity methods.
- Likely source file: [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_LightingObjectPane.cpp`

## Class Purpose

`LightingObjectPane` is the `ObjectPane` subclass for live map light sources. It stores light type, radius, intensity, and color, stores a constructor-supplied attached object/light-binding interface pointer at `+0x134`, and refreshes that relationship when intensity changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x0053c5e0-0x0053c640` | Builds the `ObjectPane` base with object type `10`, stores light parameters, and installs three vtable views. |
| non-deleting destructor | `0x0053c640-0x0053c6a1` | Calls release virtual slot `19` on the attached object/light-binding pointer, then destroys the base object pane. |
| `SetIntensity` | `0x0053c980-0x0053c9b5` | If the value changed, calls release/rebind virtual slots on the attached object/light-binding pointer and stores the new intensity. |
| scalar deleting destructor | `0x0053d380-0x0053d422` | Performs full lighting teardown and optionally frees the object. |
| neighboring light-table apply helper | [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) | Now documented under AttachmentAnchorResolver-adjacent ownership; callers compute/resolve attachment anchors before calling it. |

## Evidence Notes

- Constructor callers include map/effect paths at `0x0050a940` and `0x00530d00`.
- `SetIntensity` callers are `0x00530d00` and [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) animation update at `0x005389d0`.
- `0x0053c700-0x0053c92e` is adjacent but belongs to [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md), not this class.

## Cross-References

- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- [UID:0001DG][0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle](by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md)
- [UID:0001DI][0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity](by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md)
- [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md)
- [UID:0001DM][0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor](by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md)
- [UID:00009R][ObjectPane](by-class/ObjectPane.md)
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `80/84`. Summary: lifecycle, intensity mutation, owned interface teardown/rebind, caller evidence, and adjacent non-owner split are documented well, but one probable light-manager virtual still needs final owner confirmation. Evidence: constructor/destructor/set-intensity memory pages, `EffectObjectPane` caller evidence, object type `10`, interface slots `18`/`19`, and `AttachmentAnchorResolver` exclusion note.
- 2026-06-01 `+0x134` wording correction: existed before as an owned lighting interface claim; changed to constructor-supplied attached object/light-binding interface pointer. Evidence: IDA MCP constructor stores the first constructor argument at `+0x134`, creator paths pass the source object pane, and SetIntensity/destructors invoke slots `18`/`19` through that pointer.
- 2026-06-03 neighbor resolution update: existed before with `0x0053c9c0-0x0053c9eb` as a probable unresolved LightingObjectPane virtual; changed to link [UID:0002TZ][0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight](by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md) as an AttachmentAnchorResolver-adjacent helper. Evidence: restarted IDA MCP caller-context checks show `0x0053c9c0` follows attachment bounds/intersection and anchor resolution, not the `SetIntensity` caller set.
