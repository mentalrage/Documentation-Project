*** UID:00007G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LogoPane

## Status

- Confidence: strong for behavior and startup ownership.
- Likely source file: [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- Address range: [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- Current recovered file: `source-3/simroot_v2/class_LogoPane.cpp`

## Class Purpose

`LogoPane` displays the static startup logo, loads and inflates the `.LGO` image, draws it through the tile/palette path, and advances startup after a timer or user click. It owns the completion callback that hands control back to the application startup flow.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x004f4c10-0x004f4eac` | Initializes pane/vtables, reads compressed logo pixels and palette, builds mask data, attaches to layer, and registers delayed-ready callback. |
| non-deleting destructor body | `0x004f4eb0-0x004f4f29` | IDA-confirmed cleanup body omitted from current Wave3 active partition. |
| `BlitLogoFrame` | `0x004f4f70-0x004f4f94` | Blits the decoded logo frame with palette/mask state. |
| `HandleAdvanceRequest` | `0x004f4fa0-0x004f4fde` | Stops startup effect and queues screen advancement when loaded, otherwise records early click. |
| `OnMouseDown` | `0x004f4fe0-0x004f502c` | Handles mouse-up/click skip path. |
| `AdvanceToNextScreenCallback` | `0x004f5030-0x004f5040` | Tiny callback wrapper around `QueueAdvanceToNextScreen`. |
| `MarkReadyAndScheduleAdvance` | `0x004f5040-0x004f506a` | Marks load-ready and schedules delayed or immediate advance. |
| `AdvanceToNextScreen` | `0x004f5070-0x004f50a1` | Invokes and destroys completion callback, shows cursor, and marks pane for deletion. |
| `QueueAdvanceToNextScreen` | `0x004f5250-0x004f52de` | Allocates a deferred member callback for `AdvanceToNextScreen`. |
| deleting-destructor thunks | `0x004f52de`, `0x004f52e9` | Compiler adjustor thunks; subtract `0xa0`/`0xa4` and forward to `0x004f5300`. |
| scalar deleting destructor | `0x004f5300-0x004f53a8` | Resets vtables, releases image/palette/base state, and optionally deletes. |

## Data Notes

- `word_66DA94` and `word_66DA98` provide the startup logo/screen width and height.
- `dword_69BE14` is the file-open callback used for the logo file.
- `dword_67A7CC` and `g_pTileImageLib` are callback/tile scheduling dependencies.
- `dword_69B36C` is used when attaching the pane to the startup layer.

## Evidence Notes

- IDA xrefs show `LogoPane::LogoPane` is constructed from application startup around `0x004f643c`.
- The logo resource format is image-size dword, compressed image bytes, palette-size dword, palette bytes.
- `MarkReadyAndScheduleAdvance` schedules a `3000` ms delay unless the user has already clicked.
- Current active generated output includes an unrelated `HeadSelectDialog` callback alias and duplicate normalized include comments near the file header. Ignore those as generated-source artifacts.
- Disabled generated output marks `0x004f52e9` missing, but IDA confirms it as the second `0xb` adjustor thunk.

## Cross-References

- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/86`. Summary: the static startup-logo pane is documented across resource loading, palette/mask setup, timer/click advancement, callback lifecycle, globals, cleanup, and generated artifact caveats. Evidence: linked `LogoPane` memory range, resource format notes, application startup constructor xref, delay/skip behavior, and confirmed adjustor thunk/destructor details.
- 2026-06-01 autogen attachment:
  - Marked reconstructable and attached to [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) after the parent file was assigned to `NexusTK/app/`.
  - C++ remains blank because the class-level declarations and exact member names are not final-source quality.
