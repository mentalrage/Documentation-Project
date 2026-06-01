*** UID:0000QZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pFpsPane

## Status

- Symbol kind: global pointer
- Address: `0x0069b334` (`dword_69B334` in IDA)
- Likely type: `FpsPane*`
- Likely owner file: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Confidence: strong

## Behavior

`g_pFpsPane` stores the active FPS overlay singleton. `FpsPane::FpsPane` sets it, while `FpsPane` destructor paths clear it.

## Evidence

- IDA MCP xrefs to `0x0069b334` are in the FpsPane constructor range, non-deleting destructor, and scalar deleting destructor.
- Wave3 `class_FpsPane.cpp` declares `g_pFpsPane` as active global data.

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/82`. Summary/evidence: the page documents address, type/owner, FPS-pane singleton behavior, constructor/destructor xrefs, generated declaration, and refs; it is narrower and less detailed than the related diagnostics/global flag pages.
