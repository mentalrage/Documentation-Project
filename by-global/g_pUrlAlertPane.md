*** UID:0000SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pUrlAlertPane

## Status

- Symbol kind: process-wide singleton pointer.
- Address: `0x0069b4dc`
- IDA name: `dword_69B4DC`
- Likely source module: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Generated output target: `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`
- Confidence: strong.

## Purpose

`g_pUrlAlertPane` tracks the active [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), if one is displayed. The constructor stores the new pane pointer, the teardown paths clear it, and an external alert-open guard reads it to prevent overlapping URL alert panes.

## Score Rationale

- Completion `78`: raised from `70` after the 2026-06-03 live IDA pass confirmed the exact storage item, initial value, full six-xref lifecycle, surrounding singleton-slot context, constructor callers, and the duplicate-open guard. It is not higher because the final original declaration spelling/linkage and every caller's source-level semantic name are still below the final reconstruction bar.
- Confidence `88`: strong for address, storage shape, lifecycle writes/clears, active-alert read, URL buffer offset, exit flag offset, and [UID:0000HE][AlertPanes](by-file/AlertPanes.md) ownership. It remains below `95` because no final C++ declaration is emitted and the owner placement is still documented as a high-confidence source-module assignment rather than proven original source text.

## Evidence Notes

- Live IDA MCP rechecked `0x0069b4dc` on 2026-06-03 in `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`; IDA names it `dword_69B4DC` and the initial dword is `0xffffffff`.
- The full data-xref set is six sites: the active-alert guard read at `0x00508fd6`, constructor writes at `0x00599a94` and `0x00599a9b`, normal destructor clear at `0x00599b73`, singleton-clear helper at `0x00599bd0`, and scalar deleting destructor clear at `0x00599c5a`.
- `0x00599a40-0x00599b19` constructs the pane, calls the alert-pane base constructor, writes `this` to the singleton, installs the `UrlAlertPane` vtables, stores the URL buffer pointer at `+0x270`, stores the exit-after-open flag at `+0x274`, copies the URL bytes, and terminates the buffer.
- `0x00599b20-0x00599b92` and `0x00599c00-0x00599cb3` free the URL buffer and clear the singleton during normal and scalar-deleting teardown.
- `0x00599ba0-0x00599bcf` confirms the object role: it calls `ShellExecuteA` on the stored URL and optionally requests application exit when the `+0x274` flag is set.
- `0x00508f60-0x0050902b` reads `dword_69B4DC` and refuses to allocate another alert pane when this singleton is non-null; constructor xrefs to `0x00599a40` were rechecked at `0x00503034`, `0x00513f7e`, and `0x0051402f`.
- The surrounding slot run `0x0069b4c8-0x0069b4ec` is a sequence of adjacent `0xffffffff`-initialized UI singleton pointers, with `g_pUrlAlertPane` occupying the `0x0069b4dc` slot.

## Cross-References

- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:70`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000HE` for [UID:0000HE][AlertPanes](by-file/AlertPanes.md). `RECONSTRUCTION_CPP CODE` remains blank because the page is below the 95+ final-source threshold.
  - Evidence: IDA MCP rechecked `0x0069b4dc` as a 4-byte singleton pointer with 6 data xrefs spanning active-alert checks, UrlAlertPane construction, cleanup, normal destructor, and scalar deleting destructor.
- 2026-06-03: Raised completion/confidence from `70/84` to `78/88`.
  - Reason: live IDA MCP reconfirmed the exact global, all six data xrefs, constructor caller set, duplicate-open guard, URL buffer/exit flag offsets, and the neighboring singleton-slot inventory.
  - Boundary: no final C++ declaration was emitted because original source spelling/linkage and complete caller semantic names remain below the `95/95` reconstruction threshold.
