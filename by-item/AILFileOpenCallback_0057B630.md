*** UID:0000TU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AILFileOpenCallback_0057B630

## Status

- Confidence: strong for behavior, medium for final name.
- Address range: `0x0057b630-0x0057b72a`
- Current IDA name: `sub_57B630`
- Proposed source owner: [UID:0000NV][SoundManager](by-file/SoundManager.md)
- Related file layer: [UID:0000JD][FileIO](by-file/FileIO.md)

## Function Role

This is the Miles Sound System file-open callback registered by `SoundManager::ReinitializeAudioDriver`. It converts the incoming ANSI path to wide text, first probes the DAT archive via [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), and falls back to local filesystem existence via [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md).

If the name resolves in DAT, it allocates and constructs a [UID:00003G][DATFile](by-class/DATFile.md). If the name exists as a loose file, it allocates and constructs a [UID:0000E6][StdioFile](by-class/StdioFile.md). It then calls the selected reader's virtual `Open` slot and returns the `File*`-style handle to Miles through the output parameter.

## Callback Family

IDA shows `SoundManager::ReinitializeAudioDriver` registers these callbacks together through `AIL_set_file_callbacks`:

| Address | Role |
| --- | --- |
| `0x0057b630` | open callback; selects `DATFile` or `StdioFile`. |
| `0x0057b730` | close callback; calls virtual deleting destructor on the `File` object. |
| `0x0057b750` | seek callback; forwards to the virtual seek slot and returns position. |
| `0x0057b7a0` | read callback; clamps read count to remaining bytes and forwards to the virtual read slot. |

## Ownership Notes

Keep these callbacks in `audio/SoundManager.cpp`, not in `util/File.cpp`. They are generic in the sense that they consume the `File` API, but IDA xrefs show they are installed only as Miles AIL callbacks by the sound driver setup path.

## Cross-References

- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0001IC][0x0057b490-0x0057bc58.SoundManagerDriverAndDestructor](by-memory/0x0057b490-0x0057bc58.SoundManagerDriverAndDestructor.md)
- [UID:0000JD][FileIO](by-file/FileIO.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0000E6][StdioFile](by-class/StdioFile.md)
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented the Miles file-open callback, DAT/loose-file selection, callback family, and SoundManager ownership but remained unevaluated.
  - After: score reflects documented callback behavior and ownership, with remaining confidence limited by final callback name polish.
  - Evidence: IDA notes tie the callback family to `SoundManager::ReinitializeAudioDriver` and show DAT probe/local-file fallback plus `DATFile`/`StdioFile` construction.
