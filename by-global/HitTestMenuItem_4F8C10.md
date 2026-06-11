*** UID:0000T1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HitTestMenuItem_4F8C10

## Status

- Confidence: strong.
- Address range: [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md)
- Symbol kind: file-local helper function.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Behavior

`HitTestMenuItem_4F8C10` maps a mouse position to a main-menu item index.

Observed behavior:

- reads the menu count byte at owner offset `+0xf9`;
- iterates menu indices from `0` up to that count;
- builds the same high-resolution or low-resolution item rectangle family as [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md);
- calls the shared point-in-rectangle helper and returns the first hit index;
- returns `-1` when no menu item contains the point.

The high-resolution branch uses left/right `781..972` and vertical rows beginning at `493` with height `39` and pitch `41`. The low-resolution branch uses left/right `467..640` and vertical rows beginning at `299` with height/pitch `30`.

## Evidence

- IDA MCP `lookup_funcs 0x004f8c10` reports `sub_4F8C10`, size `0xea`.
- IDA MCP callers are only `MainMenuPane::OnMouseEvent` call sites at `0x004f6b37` and `0x004f6b6f`.
- IDA MCP callees are the rectangle builder at `0x004b7c50`, point containment helper at `0x004b7e80`, and compiler security-cookie check.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4F8C10`, size `0xea`, the same two `MainMenuPane::OnMouseEvent` callers, rectangle builder `0x004b7c50`, point containment helper `0x004b7e80`, and security-cookie check.

## Source Placement

Keep this as a private/static helper in `login/MainMenuPane.cpp`, next to [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md). It should not become a standalone source file and should not be owned by generic rectangle/input code.

## Cross-References

- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md)
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented menu hit-test behavior, constants, caller/callee evidence, and source placement but remained unevaluated.
  - After: score reflects near-complete behavior and ownership documentation for this small main-menu helper.
  - Evidence: IDA notes confirm function size, only `MainMenuPane::OnMouseEvent` callers, rectangle-builder/point-containment callees, and source placement.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Reason: live IDA MCP recheck confirms source-authored main-menu hit-test helper behavior and only main-menu mouse-event callers.
