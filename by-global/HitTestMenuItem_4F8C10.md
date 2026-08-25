*** UID:0000T1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// HitTestMenuItem is emitted by exact helper [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md); this address-suffixed global page is an alias/search marker and does not duplicate the hit-test body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HitTestMenuItem_4F8C10

## Status

- Confidence: very strong for behavior, bounds, caller set, callee set, layout dependency, and MainMenuPane ownership; medium-high for final helper spelling and surrounding source migration.
- Address range: [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md)
- Symbol kind: address-suffixed alias/index for a file-local helper function.
- Source-facing name: `HitTestMenuItem`; implementation body is emitted by [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md), not duplicated from this page.
- Likely owner file: [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Behavior

`HitTestMenuItem_4F8C10` is the recovered address alias for source helper `HitTestMenuItem`, which maps a mouse position to a main-menu item index.

Observed behavior:

- reads the menu count byte at owner offset `+0xf9`, now named `m_menuItemCount`;
- iterates menu indices from `0` up to that count;
- builds the same high-resolution or low-resolution item rectangle family as [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md);
- calls the shared point-in-rectangle helper in raw order `mouseY, mouseX, rect` and returns the first hit index;
- returns `-1` when no menu item contains the point.

The high-resolution branch uses left/right `781..972` and vertical rows beginning at `493` with height `39` and pitch `41`. The low-resolution branch uses left/right `467..640` and vertical rows beginning at `299` with height/pitch `30`.

## Evidence

- IDA MCP `lookup_funcs 0x004f8c10` reports `sub_4F8C10`, size `0xea`.
- IDA MCP callers are only [UID:0004M2][0x004f6af0-0x004f6be1.MainMenuPaneHandlePointerOrMouseEvent](by-memory/0x004f6af0-0x004f6be1.MainMenuPaneHandlePointerOrMouseEvent.md) call sites at `0x004f6b37` and `0x004f6b6f`. Under the current Event field names, both use the behaviorally exact source expression `HitTestMenuItem(this, event->m_payload.m_pointer.m_y, event->m_payload.m_pointer.m_x)`; this preserves the helper's accepted `mouseY,mouseX` formal order and `PointInRect(mouseY, mouseX, ...)` behavior.
- IDA MCP callees are the rectangle builder at `0x004b7c50`, point containment helper at `0x004b7e80`, and compiler security-cookie check.
- IDA MCP recheck on 2026-06-05 confirmed `sub_4F8C10`, size `0xea`, the same two `MainMenuPane::OnMouseEvent` callers, rectangle builder `0x004b7c50`, point containment helper `0x004b7e80`, and security-cookie check.
- Live IDA MCP on 2026-06-14 rechecked `sub_4F8C10` at `0x004f8c10`, size `0xea`, 234 decimal bytes (Verified with int_convert.py), exactly two code xrefs from `MainMenuPane::OnMouseEvent`, callees limited to rectangle setup `sub_4B7C50`, point containment `sub_4B7E80`, and security-cookie checking, 12 basic blocks, and cyclomatic complexity 6.

## Source Placement

Keep this as a private/static helper in `login/MainMenuPane.cpp`, next to [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md). It should not become a standalone source file and should not be owned by generic rectangle/input code. This by-global page should remain comment/alias-only and must not emit a second C++ body while [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) carries the implementation.

The binary duplicates the rectangle formula here instead of directly calling `ComputeMenuItemRect`. B007 preserved the inline-constants form as the exact byte-for-byte fallback. B012 later set the first-draft source body on [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) to call `ComputeMenuItemRect`, because the duplicate formula includes the `index == -1` branch from the rectangle helper and is plausibly compiler-inlined source. Keep that as an implementation decision on the memory page, not as duplicate emission from this alias page.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page records exact range, size, menu-count read, layout constants, no-hit return, two mouse-event callers, rectangle/point-helper callees, ComputeMenuItemRect pairing, private MainMenuPane placement, parent/emitter route, and final helper-spelling/source-migration caveat. |
| Confidence | 90 | Live IDA MCP on 2026-06-14 matches the exact memory page [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) for bounds, callers, callees, and behavior; confidence remains below final-source quality because original helper spelling and surrounding rectangle helper names are not final. |
| Parent | [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) | Child `86/90` and direct parent `89/86` clear the strict `85/85` gate, and the nonblank emitter route targets `auto-generated/NexusTK/login/MainMenuPane.cpp`. |

## Cross-References

- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md)
- [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md)
- [UID:0000PI][ComputeMenuItemRect_4F8B90](by-global/ComputeMenuItemRect_4F8B90.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- 2026-07-13 B003 UID00036Y caller-order synchronization:
  - Scores, route, alias-only formal block, exact helper range, and accepted `mouseY,mouseX` helper contract remain unchanged.
  - Linked exact caller child UID0004M2 and recorded the two call sites' source-facing `m_y,m_x` expression. The caller naming correction does not reverse the helper or `PointInRect` parameter order.

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented menu hit-test behavior, constants, caller/callee evidence, and source placement but remained unevaluated.
  - After: score reflects near-complete behavior and ownership documentation for this small main-menu helper.
  - Evidence: IDA notes confirm function size, only `MainMenuPane::OnMouseEvent` callers, rectangle-builder/point-containment callees, and source placement.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
  - Reason: live IDA MCP recheck confirms source-authored main-menu hit-test helper behavior and only main-menu mouse-event callers.
- 2026-06-14 A003 score refresh:
  - Before: `84/88`; the page had behavior evidence but lacked a current score rationale and live recheck after MainMenuPane parent confidence improved.
  - Changed to: `86/90`, retaining [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) as canonical owner/emitter and keeping reconstruction C++ blank.
  - Summary/evidence: live IDA MCP rechecked `sub_4F8C10`, `0xea` / 234-byte size (Verified with int_convert.py), two `MainMenuPane::OnMouseEvent` xrefs, rectangle/point helper callees, and complexity summary. Final helper spelling and surrounding source names remain the blockers below final code entry.
- 2026-06-21 Supervisor Rule 26 / B007 ComputeMenuItemRect support update:
  - Replaced source-facing references to the paired helper's address-suffixed alias with [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md).
  - Added the exact-reconstruction constraint from B007: this helper duplicates the rectangle formula in the binary and should not be rewritten to call `ComputeMenuItemRect` unless a later whole-file source rewrite intentionally factors shared constants.
- 2026-06-21 B012 MainMenuHitTest source-quality sync:
  - Reframed this page as the address-suffixed alias/index for source helper `HitTestMenuItem`, with implementation emitted only by [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md).
  - Added the `m_menuItemCount` offset, raw `mouseY, mouseX` point-test order, and duplicate-body policy: B007's inline-constants body remains a byte-for-byte fallback, while the current first-draft source on [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) may call [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md).
