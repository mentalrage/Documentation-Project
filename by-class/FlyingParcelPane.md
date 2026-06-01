*** UID:000058 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FlyingParcelPane

## Status

- Confidence: strong for parcel animation helper role, medium for final exposure.
- Likely source file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Current recovered file: `source-3/simroot_v2/class_FlyingParcelPane.cpp`
- Memory range: [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)

## Class Purpose

`FlyingParcelPane` is a helper pane for animated parcel/letter delivery. It owns a small render layer/buffer, draws either the parcel alert button or letter sprite, animates toward completion, and then updates [UID:0000A6][ParcelPane](by-class/ParcelPane.md) through [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md).

## Layout Notes

The class derives from [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). Its parcel animation payload starts at `+0xf8`: frame tick, total/left/right slot bytes, a parcel-vs-letter flag, and the owned render helper pointer at `+0x100`. The `AnimateStep` callback is invoked through the tertiary view at owner `+0xa4`, so IDA references such as `this + 0x54` normalize to owner `+0xf8`.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00546ac0-0x00546b73` | `FlyingParcelPane::FlyingParcelPane` | Constructs the pane, installs three vtable views, initializes target/state fields, and allocates an owned `Layer`/render helper. |
| `0x00546b80-0x00546bb5` | [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) | Restores `FlyingParcelPane` vtables, releases the owned helper at `+0x100`, and tail-jumps to base pane teardown. IDA currently does not wrap this start as a function. |
| `0x00546bc0-0x00546d64` | [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) | Configures parcel/letter animation fields, invalidation rectangles, old/new rendering-mode behavior, and a 10 ms or 100 ms timer. IDA currently does not wrap this start as a function. |
| `0x00546d70-0x00546ded` | `AnimateStep` | Continues a short 10 ms animation or, after the frame limit, removes itself and updates `g_pParcelPane`. |
| `0x00546df0-0x00546e6a` | `DrawParcel` | Draws `ALERTBTN.EPF` frame 5 or `LETTER.EPF` frame 0 with the matching palette. |
| `0x00546e8b-0x00546ea1` | destructor adjustor thunks | Secondary/tertiary vtable thunks forwarding to the scalar deleting destructor. Compiler-generated; see [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md). |
| `0x00546ed0-0x00546f36` | scalar deleting destructor | Releases the owned render helper and destroys the pane base. |

## Evidence Notes

- IDA MCP confirms the constructor, animation, drawing, thunk, and scalar-destructor starts; raw IDA disassembly and prewave confirm the currently unwrapped `0x00546b80` and `0x00546bc0` starts.
- IDA raw disassembly confirms additional `FlyingParcelPane` bodies at `0x00546b80` and `0x00546bc0`, even though current IDA `lookup_funcs` reports both as "Not a function". 2026-06-01 bounded disassembly and byte reads split those bodies into exact child pages and confirm padding at `0x00546bb5-0x00546bc0` and `0x00546d64-0x00546d70`.
- IDA MCP vtable dump places `DrawParcel` at primary slot `+0x44` and `AnimateStep` at tertiary slot `+0x04`. The tertiary table ends before adjacent `ALERTBTN.EPF` string data at `0x00621d50`, so disabled generated rows such as `0x00420054` are stale data artifacts.
- `AnimateStep` calls the parcel pane singleton, updates parcel slot data, marks new parcel state, and invalidates its bounds.
- Wave3 metadata reports control-character name warnings for this class, so use IDA boundaries and behavior before trusting generated method labels.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md)
- [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md)
- [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md)
- [UID:0001EN][0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)

## Changes

- 2026-05-31: Marked reconstructable and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md); split the IDA-wrapped constructor, animation step, and draw helper into exact child pages.
  - Before: class evidence was documented but validator autogen metadata was blank and several wrapped methods had no exact by-memory page.
  - After: `RECONSTRUCTABLE:TRUE` with file parent set; C++ remains blank because helper object type, scheduler names, and render APIs are not final-source ready.
  - Evidence: IDA MCP confirms constructor `0x00546ac0`, animation step `0x00546d70`, draw helper `0x00546df0`, scalar destructor `0x00546ed0`, and raw lifecycle/start bodies retained in the existing raw aggregate page.

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: parcel animation purpose, layout payload, vtable evidence, method ranges, raw unwrapped function starts, and singleton interactions are documented; remaining risk is final exposure/source split and some IDA function-boundary caveats. Evidence: parcel notification memory pages, vtable/layout cross-references, raw lifecycle page `0x00546b80-0x00546d64`, and scalar destructor page `0x00546ed0-0x00546f36`.

- Before: raw cleanup/start bodies were only described through the aggregate `0x00546b80-0x00546d64` page.
- Changed to: exact child pages now document `0x00546b80-0x00546bb5` and `0x00546bc0-0x00546d64`, and class completion/confidence are raised to `82/84`.
- Summary/evidence: 2026-06-01 IDA MCP bounded disassembly, vtable xrefs, and byte checks confirm the raw method boundaries and padding while final field/API names remain below C++ rewrite quality.
