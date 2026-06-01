*** UID:0000EP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextEditScrap

## Status

- Confidence: strong.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x00594f30-0x00595388`, `0x005956b0-0x00595758`, and restored destructor `0x00594f70-0x00594fdf`
- Current recovered file: `source-3/simroot_v2/class_TextEditScrap.cpp`

## Class Purpose

`TextEditScrap` is the clipboard scrap object used by text editing. It stores copied UTF-16 text plus an optional binary/style payload, duplicates those buffers when queried, converts multibyte text into UTF-16 when needed, and cleans up owned buffers on clear/destruction.

## Observed State

Important recovered state:

```text
+0x000  vtable
+0x004  text length
+0x008  text buffer pointer
+0x00c  payload size
+0x010  payload buffer pointer
```

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00594f30-0x00594f67` | `TextEditScrap::TextEditScrap` | Construct empty scrap buffer. |
| `0x00594f70-0x00594fdf` | `TextEditScrap::~TextEditScrap` | Restored non-deleting destructor; clears buffers and chains to `LObject`. |
| `0x00594ff0-0x0059502f` | `Clear` | Free text and payload buffers. |
| `0x00595050-0x005950db` | `SetText`, `SetPayload` | Copy UTF-16 text or payload bytes into owned storage. |
| `0x005950e0-0x00595192` | `GetText`, `GetPayload` | Return duplicated buffers to the caller. |
| `0x00595250-0x00595388` | `SetFromMultiByte` | Convert multibyte text into the scrap's UTF-16 storage. |
| `0x005956b0-0x00595758` | scalar deleting destructor | Flag-gated deleting destructor. |

## Evidence Notes

- `TextEditPane::OnKeyEvent` constructs local `TextEditScrap` objects on copy and cut paths.
- `TextEditPane::CopySelectionToScrap` fills the scrap from selected text and style payload.
- `TextEditPane::PasteFromClipboard` consumes a scrap when pasting text into the editor.
- The old memory report confirms the plain destructor was restored separately from the scalar deleting destructor.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents clipboard-scrap role, layout, constructor/destructor/clear/set/get/convert/scalar-destructor methods, and usage from copy/cut/paste paths; remaining completion gap is source-ready C++ detail.
