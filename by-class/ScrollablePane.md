*** UID:0000CF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollablePane

## Status

- Confidence: strong.
- Likely source file: [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- Main address ranges: `0x0055e660-0x0055f242` and `0x005654ec-0x00565608`
- Current recovered file: `source-3/simroot_v2/class_ScrollablePane.cpp`

## Class Purpose

`ScrollablePane` is a base pane for content areas that need optional horizontal and vertical scrollbars. It constructs the base `Pane`, owns two `ScrollPane` children, lays them out around the content rectangle, clips the visible region to the scroll content rectangle, and forwards input to the scrollbar children before letting the owner handle it.

## Observed State

Important recovered state:

```text
m_scrollX / m_scrollY                 current content offset
m_hasHorizontalScroll / m_hasVerticalScroll
m_pHScrollPane / m_pVScrollPane       owned ScrollPane children
m_contentRect / m_viewportRect        content and visible area
high/low resolution thickness tables  layout-dependent scrollbar size
```

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/layout | `0x0055e660`, `0x0055e840`, `0x0055ec00` | Construct base and child scrollbars, toggle visibility, compute high/low resolution scrollbar bounds. |
| Layer membership | `0x0055ee10`, `0x0055ef10` | Add/remove owned scrollbar panes alongside the base pane. |
| Input forwarding | `0x0055ef50`, `0x0055f0d0`, `0x0055f130` | Route mouse/key events through scrollbars before owner fallback. |
| Region update | `0x0055f190` | Temporarily clips visible region to content, runs scroll update, restores original region. |
| Destructor/defaults | `0x005654ec-0x00565608` | Destructor adjustor thunks, owned scrollbar destruction, and default content/range/offset virtuals. |

## Evidence Notes

- IDA MCP reports six direct constructor callers: `ChattingPane`, `FolderTreePane`, `ListPane`, `SystemMessagePane`, `OldSystemMessagePane`, and `TextEditPane`.
- Constructor directly allocates `ScrollPane(1)` and `ScrollPane(0)`.
- Destructor deletes both owned scrollbar children before chaining to `Pane`.
- Default `GetContentWidth`, `GetContentHeight`, `GetScrollRange`, and `GetScrollOffset` return zero, while `IsScrollable` returns one; derived classes provide real content extents.

## Cross-References

- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0001GL][0x0055e660-0x0055f242.ScrollablePaneCore](by-memory/0x0055e660-0x0055f242.ScrollablePaneCore.md)
- [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence were `0/0` even though the page documented owned horizontal/vertical scrollbars, layout/input families, constructor callers, and the corrected destructor/default range.
  - After: changed completion/confidence to `78/84`.
  - Evidence: existing class purpose, observed state, method families, IDA constructor/destructor evidence, and endpoint correction support strong class-role confidence.

- 2026-05-28: Changed the destructor/default virtual range from `0x00565510-0x00565607` to `0x005654ec-0x00565608`.
  - Before: the class doc omitted two destructor adjustor thunks and the final byte of `IsScrollable`.
  - After: the class doc includes the full destructor/default cluster.
  - Evidence: IDA MCP reports adjustor thunks at `0x005654ec` and `0x005654f7`, target scalar deleting destructor at `0x00565510`, and `sub_565600` ending at `0x00565608`.
- [UID:0000CM][ScrollPane](by-class/ScrollPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- 2026-06-03: Attached class metadata to ScrollBar.
  - Before: the page was `78/84`, but reconstructability and parent metadata were blank.
  - After: marked reconstructable and attached to [UID:0000NF][ScrollBar](by-file/ScrollBar.md) at position `30`, with C++ blank.
  - Evidence: Existing constructor/destructor/layout/input evidence already meets the parent-attachment threshold, and the ScrollWidget pass reconfirmed the `ScrollablePane` constructor creates both horizontal and vertical `ScrollPane` children plus later sync helpers call the embedded scroll widgets.
