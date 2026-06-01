*** UID:00009Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayImageEffecter

## Status

- Confidence: strong for role and ownership; medium for helper names in generated output.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_OverlayImageEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayImageEffecter` is the static image/name overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It resolves overlay metadata by image name, stores the lookup name pair, and applies the overlay to the current viewport bounds.

Generated helper labels mention fitting-room/download panes because the shared overlay helper is also used there. Treat those labels as helper provenance, not proof that this runtime effect class belongs in fitting-room source.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a440-0x0055a498` | `ApplyOverlayImage` | IDA confirms it fetches viewport bounds through `0x004b8e00` and calls the overlay-by-name renderer. |
| `0x0055a4a0-0x0055a55d` | constructor | Builds `OverlayEffecter`, installs subclass vtables, initializes overlay metadata, and loads catalog metadata. |
| `0x0055bd70-0x0055be0c` | scalar deleting destructor | Resets to `OverlayEffecter`/`ScreenEffecter` bases and conditionally deletes storage. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite role, method, helper-label caveat, and overlay-family documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
- Evidence: apply/constructor/destructor methods, static image overlay responsibility, base/subclass relationships, and generated helper-label pollution are documented; confidence stays medium-high because helper names and detailed field/source split still need verification.
