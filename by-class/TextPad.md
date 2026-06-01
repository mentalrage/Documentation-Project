*** UID:0000EU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextPad

## Status

- Confidence: strong for recovered behavior, medium for activation path.
- Likely source: [UID:0000OQ][TextPad](by-file/TextPad.md)
- Current recovered source: `source-3/simroot_v2/class_TextPad.cpp`
- Memory: [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)

## Responsibility

`TextPad` is a full-screen text editing pad built on `DialogPane` and `TextEditControlPane`. It creates:

- control `0`: main read-only `TextEditControlPane`, screen width by `screen height - 32`, max 2000 lines and 30000 chars;
- control `1`: bottom single-line input `TextEditControlPane`, height 32 pixels.

When the bottom input receives Enter, `TextPad` reads the input text, passes it to a private command helper, then selects all input text.

## Method Families

| Range | Method | Summary |
| --- | --- | --- |
| `0x00595900-0x00595ae2` | constructor | Constructs base `DialogPane`, installs three vtables, builds the main and input text edit controls, and attaches to root/cursor managers. |
| `0x00595af0-0x00595ba9` | `OnKeyInput` | Handles Enter command submission or falls back to `DialogPane::OnKeyInput`. |
| `0x00595bb0-0x00595bcf` | `OnClose` | Clears visibility/style and invalidates the pane rect. |
| `0x00595bd0-0x00595bd1` | empty virtual | Null vtable target. |
| [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) | `TextPad_SendText` | Private helper for file and formatting commands. |

## Command Helper

IDA disassembly for [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) shows prefix-based command handling:

| Prefix | Behavior |
| --- | --- |
| `Open ` | Opens the named file, reads content, converts it into the main text edit object, and resets selection. |
| `Save ` | Serializes the main text edit content and optional object/style payload, then writes it to the named file. |
| `SetFont ` | Parses a numeric font/style argument and applies edit formatting command `1`. |
| `SetColor ` | Parses a numeric color argument and applies edit formatting command `2`. |

The exact serialized text-object format used by `Open` and `Save` depends on adjacent `TextEditPane` helper functions around `0x00594f30-0x00595140` and should be documented with [UID:0000ON][TextEditPane](by-file/TextEditPane.md) when that format is reconstructed.

## Unresolved

- No direct constructor caller is currently visible through IDA xrefs. The activation path remains open.
- Active generated output omits [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md) from the emitted source and class method list even though `OnKeyInput` calls it.
- 2026-05-26 IDA MCP recheck confirms that helper has one direct code caller, `0x00595b64` inside `TextPad::OnKeyInput`, so it remains reconstructable `TextPad` private code.
- The original folder could have been a diagnostic/editor utility area rather than generic `ui/dialogs/`; `ui/dialogs/TextPad.cpp` is the current staging path because the class derives from `DialogPane` and uses UI controls.

## Cross-References

- [UID:0000OQ][TextPad](by-file/TextPad.md)
- [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md)
- [UID:0001JW][0x00595be0-0x00595f26.TextPadCommandHelper](by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the documented constructor, key-input flow, private command helper, command-prefix behavior, memory/file cross-references, and explicit unresolved activation/generated-output caveats.
